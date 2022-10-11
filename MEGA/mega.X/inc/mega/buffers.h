/*
 * Data_Store.h
 *
 * Created: 2022-02-15 10:04:55 AM
 *  Author: Mahmoud Shoaib
 */ 


#ifndef DATA_STORE_H_
#define DATA_STORE_H_


void byteBufferInit(stByteBufDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize);
void structBufferInit(stBufferStructDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize, uint8_t structSize);
void TLVBufferInit(stBufferTLVDescriptor_t* Buf, uint8_t* storeBuf, uint8_t storeBufSize);
uint8_t Buffer_Is_Empty(stByteBufDescriptor_t* Buf);
uint8_t Buffer_Is_Full(stByteBufDescriptor_t* Buf);
uint8_t getByte(stByteBufDescriptor_t* Buf, uint8_t* Data_Ptr);
uint8_t putByte(stByteBufDescriptor_t* Buf, uint8_t Data);
uint8_t getExistingLength(stByteBufDescriptor_t* Buf);
uint8_t getTlvCount(stBufferTLVDescriptor_t* Buf);
uint8_t getStructCount(stBufferStructDescriptor_t* Buf);
uint8_t putStruct(stBufferStructDescriptor_t * structBuf, void* Struct_Ptr);
uint8_t getStruct(stBufferStructDescriptor_t* structBuf, void* Struct_Ptr);
uint8_t putTLV(stBufferTLVDescriptor_t * TLVBuf, void* TLV_Ptr);
uint8_t getTLV(stBufferTLVDescriptor_t* TLVBuf, void* TLV_Ptr);



#endif /* DATA_STORE_H_ */