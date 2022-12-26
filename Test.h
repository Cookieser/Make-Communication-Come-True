#include <iostream>
#include<string>
#include <map>
using namespace std;

class Test
{

private:

    typedef char* (Test::* pFunc)(char*);

    std::map<std::string, pFunc> m_mFuncPtr;



    //-------------------------------------------------------------------------------------
    // ADD SOMETHING HERE...

    char* process1(char *strBuffer){

        //std::cout << "this is print1 func..." << std::endl;


        int num = atoi(strBuffer);
        //cout <<num<<endl;
        num=num+10;
        sprintf(strBuffer,"%d",num);

        //cout<<num<<endl;

        return strBuffer;
    }
    char* process2(char *strBuffer){

        //std::cout << "this is print2 func..." << std::endl;


        int num = atoi(strBuffer);
        //cout <<num<<endl;
        num = num * 10;
        sprintf(strBuffer,"%d",num);

        //cout<<num<<endl;

        return strBuffer;
    }
    char* process3(char *strBuffer){

        //std::cout << "this is print3 func..." << std::endl;


        int num = atoi(strBuffer);
        //cout <<num<<endl;
        num=num-10;
        sprintf(strBuffer, "%d",num);

        //cout<<num<<endl;

        return strBuffer;
    }





    //-------------------------------------------------------------------------------------


public:
    Test()
    {
        auto map_insert = [&](std::string key, pFunc ptr)
        {
            m_mFuncPtr.emplace(std::make_pair(key, ptr));
        };
        //-------------------------------------------------------------------------------------
        map_insert("process1", &Test::process1);
        map_insert("process2", &Test::process2);
        map_insert("process3", &Test::process3);

        //-------------------------------------------------------------------------------------
    }



    void manipulate(const std::string& func,char* strBuffer)
    {
        auto it = m_mFuncPtr.find(func);
        if (it == m_mFuncPtr.end() || nullptr == it->second)
        {
            return;
        }

        (this->*it->second)(strBuffer);    //调用函数
    }


    ~Test() = default;

};


/*
// A demo can test this class below
 int main()
{
    char strBuffer[1024];
    memset(strBuffer,0,sizeof(strBuffer));
    strcat(strBuffer, "123");


    Test test;
    test.manipulate("process1",strBuffer);

    return 0;
}

*/
