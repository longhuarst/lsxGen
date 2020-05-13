//
// Created by lsxs on 2020/5/13.
//

#ifndef DATASTRUCTWITHSIMPLEECC_SIMPLEECCOBJECT_H
#define DATASTRUCTWITHSIMPLEECC_SIMPLEECCOBJECT_H

#include <stdint.h>
#include <stdlib.h>
#include "crc32.h"




//当前版本只是存多份 取出第一次校验通过的那份数据
// FIXME : 下个版本需要 增加:   比特对比， 找出最有可能的正确 bit 进行替换。




#define type int
#define SimpleEccObjectStoreSize (5)
#define SimpleEccObjectCRC32
//#deifne SimpleEccObjectCRC16
//#define SimpleEccObjectSUM32

typedef struct {
    struct {
        ///
        type data;
#ifdef SimpleEccObjectCRC32
        uint32_t crc32;
#endif
#ifdef SimpleEccObjectCRC16
        uint16_t crc16;
#endif
#ifdef SimpleEccObjectSUM
        uint32_t sum32;
#endif
    }object[SimpleEccObjectStoreSize];
}SimpleEccObject;


extern void SimpleEccObject_Init(SimpleEccObject * obj);
extern void SimpleEccObject_Set(SimpleEccObject * obj, type element);
extern type * SimpleEccObject_Get(SimpleEccObject * obj);




















#endif //DATASTRUCTWITHSIMPLEECC_SIMPLEECCOBJECT_H
