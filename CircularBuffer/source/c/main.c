//
// Created by coocx on 2020/5/2.
//
#include "FixedCircularBuffer.h"

#include <stdio.h>





int main(){

    FixedCircularBuffer fcb;
    FixedCircularBuffer_Init(&fcb);

    printf("fcb->length = %d\r\n", FixedCircularBuffer_Length(&fcb));

    FixedCircularBuffer_PushBack(&fcb, 15);

    printf("fcb->length = %d\r\n", FixedCircularBuffer_Length(&fcb));


    int value;

    if (FixedCircularBuffer_PopFront(&fcb, &value)){
        printf("fcb popfront success value = %d\r\n", value);
    }else{
        printf("fcb popfront error \r\n");
    }

    printf("fcb->length = %d\r\n", FixedCircularBuffer_Length(&fcb));

    for (int i=0;i<1024; ++i){
        FixedCircularBuffer_PushBack(&fcb, i);
        printf("fcb->length = %d \t front = %d \t back = %d \r\n", FixedCircularBuffer_Length(&fcb), fcb.front, fcb.back);
    }

    for (int i=0;i<1024; ++i){
        FixedCircularBuffer_PushBack(&fcb, i);
        printf("fcb->length = %d \t front = %d \t back = %d \r\n", FixedCircularBuffer_Length(&fcb), fcb.front, fcb.back);
    }


    if (FixedCircularBuffer_PopFront(&fcb, &value)){
        printf("fcb popfront success value = %d\r\n", value);
    }else{
        printf("fcb popfront error \r\n");
    }

    printf("fcb->length = %d\r\n", FixedCircularBuffer_Length(&fcb));


}