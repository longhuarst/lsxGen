


if __name__ == '__main__':
    print("gen")

    try:
        fpc = open("./source/c/FixedCircularBuffer.c", "r", encoding='UTF-8')
        fph = open("./source/c/FixedCircularBuffer.h", "r", encoding='UTF-8')
        cfile = fpc.read()
        hfile = fph.read()

        print(cfile)
        print(hfile)



        #处理h文件

        #参数
        type = "CanFrame"
        size = 128;
        struct = True;
        name = "CanRingBuffer"





        if struct == True:
            hfile = hfile.replace("#define MEMCPY false", "#define MEMCPY true"); #如果不是基本类型的话

        hfile = hfile.replace("#define" , "//#define")
        hfile = hfile.replace("//#define C_", "#define C_")

        hfile = hfile.replace("TYPE_IDX", "uint32_t")

        hfile = hfile.replace("TYPE", type)
        hfile = hfile.replace("TYPE", "uint8_t")
        hfile = hfile.replace("#define SIZE 1024", "#define SIZE "+str(size))
        hfile = hfile.replace("SIZE", "FixedCircularBuffer_SIZE")


        cfile = cfile.replace("TYPE_IDX", "uint32_t")
        cfile = cfile.replace("TYPE", type)
        cfile = cfile.replace("SIZE", "FixedCircularBuffer_SIZE")

        if name == "":
            hfile = hfile.replace("FixedCircularBuffer", "FixedCircularBuffer_"+type+"_"+str(size));
            cfile = cfile.replace("FixedCircularBuffer", "FixedCircularBuffer_"+type+"_"+str(size));
        else :
            hfile = hfile.replace("FixedCircularBuffer", name);
            cfile = cfile.replace("FixedCircularBuffer", name);

        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")
        print("--------------------------------------------------------")

        print(hfile)
        print(cfile)

    except BaseException as error :
        print(error);





