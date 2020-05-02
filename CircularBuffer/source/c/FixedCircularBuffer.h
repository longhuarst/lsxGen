//
// Created by coocx on 2020/5/2.
//

#ifndef C_FixedCIRCULARBUFFER_H
#define C_FixedCIRCULARBUFFER_H


#include <stdbool.h>


#define TYPE int    //数据类型
#define SIZE 1024   //数据长度
#define TYPE_IDX int //游标类型


typedef struct FixedCircularBuffer {
    TYPE buffer[SIZE];//缓存
    TYPE_IDX front; //头指针
    TYPE_IDX back;//尾指针
    TYPE_IDX length; //长度
}FixedCircularBuffer;


void FixedCircularBuffer_Init(FixedCircularBuffer *fcb);
TYPE_IDX FixedCircularBuffer_Length(FixedCircularBuffer *fcb);
bool FixedCircularBuffer_IsFull(FixedCircularBuffer *fcb);
bool FixedCircularBuffer_IsEmpty(FixedCircularBuffer *fcb);
void FixedCircularBuffer_PushBack(FixedCircularBuffer *fcb, TYPE element);
bool FixedCircularBuffer_PopFront(FixedCircularBuffer *fcb, TYPE *element);


#endif //C_FixedCIRCULARBUFFER_H
