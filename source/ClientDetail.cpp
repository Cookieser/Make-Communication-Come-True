#include"../include/Test.h"



    char* ClientTest::process1(char *strBuffer){

        int num = 90;

        sprintf(strBuffer,"%d",num);


        return strBuffer;
    }

    char* ClientTest::process2(char *strBuffer){

        int num = atoi(strBuffer);

        num = num * 19;

        sprintf(strBuffer,"%d",num);

        return strBuffer;
    }

    char* ClientTest::process3(char *strBuffer){

        int num = atoi(strBuffer);

        num = num - 13;

        sprintf(strBuffer, "%d",num);

        return strBuffer;
    }
