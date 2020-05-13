//
// Created by lsxs on 2020/5/13.
//

#include "SimpleEccObject.h"

#include "SimpleEccObject.h"

#include <string.h>



//当前版本只是存多份 取出第一次校验通过的那份数据
// FIXME : 下个版本需要 增加:   比特对比， 找出最有可能的正确 bit 进行替换。





void SimpleEccObject_Init(SimpleEccObject * obj){
    memset(obj, 0, sizeof(SimpleEccObject));
}


void SimpleEccObject_Set(SimpleEccObject * obj, type element){
    for (int i=0; i<SimpleEccObjectStoreSize; ++i){
        memcpy(&obj->object[i].data, &element, sizeof(type));
#ifdef SimpleEccObjectCRC32
        obj->object[i].crc32 = crc32(&obj->object[i].data, sizeof(type));
#endif
#ifdef SimpleEccObjectCRC16
        obj->object[i].crc16 = crc16(&obj->object[i].data, sizeof(type));
#endif
#ifdef SimpleEccObjectSUM32
        obj->object[i].sum = sum32(&obj->object[i].data, sizeof(type));
#endif
    }
}


type * SimpleEccObject_Get(SimpleEccObject * obj){
    for (int i=0; i<SimpleEccObjectStoreSize; ++i){
        uint8_t correctCount = 0;
#ifdef SimpleEccObjectCRC32
        uint32_t crc32Value = crc32(&obj->object[i].data, sizeof(type));

        if (crc32Value == obj->object[i].crc32){
            correctCount++;
        }
#endif
#ifdef SimpleEccObjectCRC16
        uint16_t crc16Value = crc16(&obj->object[i].data, sizeof(type));
        if (crc16Value == obj->object[i].crc16){
            correctCount++;
        }
#endif
#ifdef SimpleEccObjectSUM32
        uint32_t sumValue = sum32(&obj->object[i].data, sizeof(type));
        if (sumValue == obj->object[i].sum32){
            correctCount++;
        }
#endif

        if (correctCount > 0){
            return &obj->object[i].data;
        }
    }
    return NULL;
}