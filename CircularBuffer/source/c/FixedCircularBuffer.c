//
// Created by coocx on 2020/5/2.
//

#include "FixedCircularBuffer.h"


void FixedCircularBuffer_Init(FixedCircularBuffer *fcb){
    fcb->front = 0;
    fcb->back = 0;
    fcb->length = 0;
}


TYPE_IDX FixedCircularBuffer_Length(FixedCircularBuffer *fcb){
    return fcb->length;
}

bool FixedCircularBuffer_IsFull(FixedCircularBuffer *fcb){
    return fcb->length == SIZE;
}


bool FixedCircularBuffer_IsEmpty(FixedCircularBuffer *fcb){
    return fcb->length == 0;
}

void FixedCircularBuffer_PushBack(FixedCircularBuffer *fcb, TYPE element){

    if (FixedCircularBuffer_IsFull(fcb) == true){
        fcb->length --;
        fcb->front = (fcb->front + 1 ) % SIZE;
    }

    fcb->buffer[fcb->back] = element;
    fcb->back = (fcb->back + 1 ) % SIZE;
    fcb->length++;
}

bool FixedCircularBuffer_PopFront(FixedCircularBuffer *fcb, TYPE *element){

    if (FixedCircularBuffer_IsEmpty(fcb) == true){
        return false;
    }
    *element = fcb->buffer[fcb->front];
    fcb->front = (fcb->front + 1 ) % SIZE;
    fcb->length--;
    return true;
}
