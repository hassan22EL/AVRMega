/*
 * File:   lcdForm.c
 * Author: Hassan
 *
 * Created on August 1, 2022, 8:39 AM
 */
#include "../../inc/mega.h"
#if FORMLCD_MODULE

stFiled_t *first;
stFiled_t *last;
stFiled_t *current;
uint8_t visible;
void lcdFormAddFiled(stFiled_t *sfiled);
void lcdFormRemoveFiled(stFiled_t *sfiled);
void lcdFormSetCurrentField(stFiled_t *field);
void lcdFormNextFiled();
void lcdFormPrvFiled();
void lcdFormDefaultField();
void lcdFormshow();
void lcdFormhide();
uint8_t isVisible();
uint8_t lcdFormIsCurrent(stFiled_t *sfiled);
void lcdFormSetCurrentLable(stFiled_t *field, const char *lable);
void lcdFormEnterField(stFiled_t *sfiled, uint8_t reverse);
void lcdFormexitField(stFiled_t *sfiled);
uint8_t lcdFormDispatch(stFiled_t *sfiled, uint8_t event);
const char * lcdFormGetCurrentLable(stFiled_t *sfiled);

void lcdFormInit() {
    first = NULL;
    last = NULL;
    current = NULL;
    visible = 0;
}

uint8_t lcdFormDispatch(stFiled_t *sfiled, uint8_t event) {
    uint8_t exitval;
    if (current) {
        exitval = lcdFormDispatch(current, event);
        if (exitval >= 0)
            return exitval;
    }
    if (event == LCD_BUTTON_LEFT)
        lcdFormPrvFiled();
    else if (event == LCD_BUTTON_RIGHT)
        lcdFormNextFiled();
    return 0;
}

void lcdFormEnterField(stFiled_t *sfiled, uint8_t reverse) {
    lcdwrite(1, 0, sfiled->lable);
}

void lcdFormexitField(stFiled_t *sfiled) {
    return;
}

const char * lcdFormGetCurrentLable(stFiled_t *sfiled) {
    return sfiled->lable;
}

void lcdFormSetCurrentLable(stFiled_t *field, const char *lable) {
    uint8_t prevLen;
    uint8_t newLen;
    uint8_t i;
    if (lcdFormIsCurrent(field)) {
        prevLen = strlen(field->lable);
        newLen = strlen(lable);
        field->lable = lable;
        lcdwrite(1, 0, field->lable);
        i = 0;
        while (newLen++ < prevLen) {
            lcdwrite(1, i, " ");
            i++;
        }
    } else {
        field->lable = lable;
    }
}

void lcdFormCreateFiled(stFiled_t *sfiled, const char *lable) {
    sfiled->lable = lable;
    lcdFormAddFiled(sfiled);
}

void lcdFormAddFiled(stFiled_t *sfiled) {
    sfiled->next = 0;
    sfiled->prv = last;
    if (last)
        last->next = sfiled;
    else
        first = sfiled;
    last = sfiled;
}

void lcdFormRemoveFiled(stFiled_t *sfiled) {
    if (current == sfiled) {
        if (sfiled->next)
            lcdFormSetCurrentField(sfiled->next);
        else if (sfiled->prv)
            lcdFormSetCurrentField(sfiled->prv);
        else
            lcdFormSetCurrentField(0);
    }
    if (sfiled->next)
        sfiled->next->prv = sfiled->prv;
    else
        last = sfiled->prv;
    if (sfiled->prv)
        sfiled->prv->next = sfiled->next;
    else
        first = sfiled->next;
    sfiled->next = 0;
    sfiled->prv = 0;
}

uint8_t lcdFormIsCurrent(stFiled_t *sfiled) {
    return current == sfiled;
}

void lcdFormshow() {
    if (!visible) {
        if (!current)
            current = first;
        visible = true;
        lcdClear();
        if (current)
            lcdFormEnterField(current, false);
    }
}

void lcdFormhide() {
    if (visible) {
        if (current)
            lcdFormexitField(current);
        visible = false;
        lcdClear();
    }

}

uint8_t isVisible() {
    return visible;
}

void lcdFormSetCurrentField(stFiled_t *field) {
    uint8_t reverse;
    if (visible) {
        reverse = false;
        if (current) {
            lcdFormexitField(field);
            if (field->next == current)
                reverse = true;
            else if (!field->next && current == first)
                reverse = true;
        }
        current = field;
        lcdClear();
        if (current)
            lcdFormEnterField(current, reverse);
    } else {
        current = field;
    }
}

void lcdFormNextFiled() {
    stFiled_t *field;
    field = current;
    if (!field)
        field = first;
    if (field && field->next)
        field = field->next;
    else
        field = first;
    lcdFormSetCurrentField(field);
}

void lcdFormPrvFiled() {
    stFiled_t *field;
    field = current;
    if (!field)
        field = last;
    if (field && field->prv)
        field = field->prv;
    else
        field = last;
    lcdFormSetCurrentField(field);
}

void lcdFormDefaultField() {
    lcdFormSetCurrentField(first);
}



#endif 
