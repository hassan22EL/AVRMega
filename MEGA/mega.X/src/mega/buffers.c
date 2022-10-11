/*
 * Data_Handle_Driver.c
 *
 * Created: 2022-02-15 10:04:41 AM
 *  Author: Mahmoud Shoaib
 */


#include "../../inc/mega.h"

void byteBufferInit(stByteBufDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize) {
    Buf->Data_Buffer = storeBuf;
    Buf->Max_Length = storeBufSize;
    Buf->Length = 0;
    Buf->Write = 0;
    Buf->Read = 0;
}

void structBufferInit(stBufferStructDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize, uint8_t structSize) {
    Buf->StructSize = structSize;
    byteBufferInit((&(Buf->stByteBufDescriptor)), storeBuf, storeBufSize);
}

void TLVBufferInit(stBufferTLVDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize) {
    byteBufferInit(&(Buf->stByteBufDescriptor), storeBuf, storeBufSize);
    Buf->TlvCount = 0;
}

uint8_t Buffer_Is_Empty(stByteBufDescriptor_t* Buf) {
    if ((Buf-> Length) == 0) return 1;
    return 0;
}

uint8_t Buffer_Is_Full(stByteBufDescriptor_t* Buf) {
    if ((Buf-> Length) == (Buf-> Max_Length)) return 1;
    return 0;
}

uint8_t getByte(stByteBufDescriptor_t* Buf, uint8_t* Data_Ptr) {
    if (Buffer_Is_Empty(Buf)) return 0;

    *Data_Ptr = *((Buf->Data_Buffer) + (Buf->Read));
    (Buf->Read)++;
    (Buf-> Length)--;

    if ((Buf-> Read) == (Buf-> Max_Length)) (Buf->Read) = 0;

    return 1;

}

uint8_t putByte(stByteBufDescriptor_t* Buf, uint8_t Data) {
    if (Buffer_Is_Full(Buf)) return 0;

    *((Buf-> Data_Buffer) + (Buf-> Write)) = Data;
    (Buf-> Write)++;
    (Buf-> Length)++;

    if ((Buf-> Write) == (Buf-> Max_Length)) (Buf-> Write) = 0;

    return 1;
}

uint8_t getExistingLength(stByteBufDescriptor_t* Buf) {
    return (Buf-> Length);
}

uint8_t getTlvCount(stBufferTLVDescriptor_t* Buf) {
    return (Buf-> TlvCount);
}

uint8_t getStructCount(stBufferStructDescriptor_t* Buf) {
    return (((Buf-> stByteBufDescriptor).Length) / (Buf->StructSize));
}

uint8_t putStruct(stBufferStructDescriptor_t * structBuf, void* Struct_Ptr) {

    if ((((structBuf->stByteBufDescriptor).Max_Length) - ((structBuf->stByteBufDescriptor).Length)) < (structBuf->StructSize)) return 0;

    uint8_t* Data_Ptr;
    Data_Ptr = (uint8_t*) Struct_Ptr;

    for (uint8_t i = 0; i < (structBuf->StructSize); i++) {
        if ((putByte((&(structBuf->stByteBufDescriptor)), *(Data_Ptr + i))) == 0) return 0;
    }

    return 1;
}

uint8_t getStruct(stBufferStructDescriptor_t* structBuf, void* Struct_Ptr) {
    uint8_t* Data_Ptr;
    Data_Ptr = (uint8_t*) Struct_Ptr;

    for (uint8_t i = 0; i < (structBuf->StructSize); i++) {
        if ((getByte((&(structBuf->stByteBufDescriptor)), (Data_Ptr + i))) == 0) return 0;
    }

    return 1;

}

uint8_t putTLV(stBufferTLVDescriptor_t * TLVBuf, void* TLV_Ptr) {
    uint8_t* Data_Ptr;
    Data_Ptr = (uint8_t*) TLV_Ptr;

    if ((((TLVBuf->stByteBufDescriptor).Max_Length) - ((TLVBuf->stByteBufDescriptor).Length)) < 2) return 0;
    if ((((TLVBuf->stByteBufDescriptor).Max_Length) - ((TLVBuf->stByteBufDescriptor).Length)) < ((*(Data_Ptr + 1)) + 2)) return 0;

    for (uint8_t i = 0; i < (*(Data_Ptr + 1) + 2); i++) {
        if ((putByte((&(TLVBuf->stByteBufDescriptor)), *(Data_Ptr + i))) == 0) return 0;
    }

    (TLVBuf->TlvCount)++;

    return 1;
}

uint8_t getTLV(stBufferTLVDescriptor_t* TLVBuf, void* TLV_Ptr) {
    uint8_t* Data_Ptr;
    Data_Ptr = (uint8_t*) TLV_Ptr;

    for (uint8_t i = 0; i < (*(Data_Ptr + 1) + 2); i++) {
        if ((getByte((&(TLVBuf->stByteBufDescriptor)), (Data_Ptr + i))) == 0) return 0;
    }

    (TLVBuf->TlvCount)--;

    return 1;

}