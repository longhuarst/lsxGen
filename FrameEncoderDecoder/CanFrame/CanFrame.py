import math

''''
    {
        xxxx:8
        xxxx:16
        sss:44

    }
'''









if __name__ == '__main__':
    print("can frame");


    name = "xxx";

    object = "{ \
        xxxx:8 \r\n\
        xxxx:16 \r\n\
        sss:44 \r\n\
    }";



    try:
        fp = open("example.txt", "r");

        fileString = fp.read();
        print(fileString)

        object = fileString;

    except Exception as error:
        print(error)


    object = object.replace("\r\n", ";");
    object = object.replace("\r", ";");
    object = object.replace("\n", ";");
    object = object.replace(" ", "")

    object = object.replace("{", "")
    object = object.replace("}","")


    objectArr = object.split(";")


    print(object)

    print(objectArr)



    bitCount = 0;
    for i in range(len(objectArr)) :
        arr = objectArr[i].split(":")
        print(arr)
        if len(arr) == 2:
            bitCount = bitCount + int(arr[1]);
    print("bitCount = "+str(bitCount))

    byteCount = math.ceil(bitCount / 8);

    print("byteCount = "+str(byteCount))


    #顺序填
    #计算
    frameLength = 0;
    if byteCount <= 6 :
        frameLength = 1;
    else:
        frameLength = math.ceil((byteCount - 6 ) / 7) + 1;

    print("frame length = " + str(frameLength))

    ######生成数据结构
    canFrameBufferStruct = "typedef struct { \r\n" \
                           "    struct FrameType { \r\n" \
                           "        uint32_t id;\r\n" \
                           "        uint8_t dlc;\r\n" \
                           "        uint8_t data[8];\r\n" \
                           "    } frame["+str(frameLength)+"];\r\n" \
                           "}"+name+"Frame;\r\n";

    print(canFrameBufferStruct);


    #####生成数据结构
    dataStruct = "typedef struct { \r\n";

    offset = 0; #偏移量
    for i in range(len(objectArr)) :
        ## 对每一个节点数据 进行分配
        if offset == 0 : ##当前的偏移量为 起始位置
            arr = objectArr[i].split(":")
            if len(arr) == 2:
                l = int(arr[1]);
                if l <= 8:
                    dataStruct = dataStruct + "    uint8_t "+arr[0]+":"+str(l)+";\r\n";
                    offset = offset + l;
                    offset = offset % 8;
                elif l <= 16:
                    dataStruct = dataStruct + "    uint16_t "+arr[0]+":"+str(l)+";\r\n";
                    offset = offset + l;
                    offset = offset % 16;
                elif l <= 32 :
                    dataStruct = dataStruct + "    uint32_t " + arr[0] + ":" + str(l) + ";\r\n";
                    offset = offset + l;
                    offset = offset % 32;
                elif l <= 64 :
                    dataStruct = dataStruct + "    uint64_t " + arr[0] + ":" + str(l) + ";\r\n";
                    offset = offset + l;
                    offset = offset % 64;
                else:
                    print("not support data bits more than 64 bit");
        # elif offset % 8 == 0: ##当前的偏移量为 8 的整数倍
        #
        # else:




    dataStruct = dataStruct + "\r\n}"+name+";"

    print(dataStruct)
