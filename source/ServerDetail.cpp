
#include"../include/Test.h"
/*
char* ServerTest::process1(char *strBuffer){

    ......

    return strBuffer;
}
*/

    char* ServerTest::process1(char *strBuffer){

        int num = atoi(strBuffer);

        num=num+10;

        sprintf(strBuffer,"%d",num);

        return strBuffer;
    }

    char* ServerTest::process2(char *strBuffer){

        int num = atoi(strBuffer);

        num = num * 10;

        sprintf(strBuffer,"%d",num);

        return strBuffer;
    }

    char* ServerTest::process3(char *strBuffer){

        int num = atoi(strBuffer);

        num = num - 10;

        sprintf(strBuffer, "%d",num);

        return strBuffer;
    }
