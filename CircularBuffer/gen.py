


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

        hfile = hfile.replace("#define" , "//#define")
        hfile = hfile.replace("//#define C_", "#define C_")

        hfile = hfile.replace("TYPE_IDX", "uint32_t")
        hfile = hfile.replace("TYPE", "uint8_t")
        hfile = hfile.replace("SIZE", "FixedCircularBuffer_SIZE")

        cfile = cfile.replace("TYPE_IDX", "uint32_t")
        cfile = cfile.replace("TYPE", "uint8_t")
        cfile = cfile.replace("SIZE", "FixedCircularBuffer_SIZE")

        hfile = hfile.replace("FixedCircularBuffer", "FixedCircularBuffer_u8_1024");
        cfile = cfile.replace("FixedCircularBuffer", "FixedCircularBuffer_u8_1024");


        print(hfile)
        print(cfile)

    except BaseException as error :
        print(error);





