#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;


class Test{
protected:
    int m_totalVolume=0;

     // Measure this volume through the message sent by two parts
     int measureVolume(char *strBuffer){

         int volume = strlen(strBuffer);

         m_totalVolume=volume+m_totalVolume;

         return volume;
     }

public:

    void simulate();

    int getTotalVolume(){ return m_totalVolume;}

};

class ServerTest: public Test
{

private:

    typedef char* (ServerTest::* pFunc)(char*);

    std::map<std::string, pFunc> m_mFuncPtr;



    //-------------------------------------------------------------------------------------
    // ADD SOMETHING HERE...

    char* process1(char *strBuffer);

    char* process2(char *strBuffer);

    char* process3(char *strBuffer);



    //-------------------------------------------------------------------------------------


public:
    ServerTest()
    {
        auto map_insert = [&](std::string key, pFunc ptr)
        {
            m_mFuncPtr.emplace(std::make_pair(key, ptr));
        };
        //-------------------------------------------------------------------------------------
        map_insert("process1", &ServerTest::process1);

        map_insert("process2", &ServerTest::process2);

        map_insert("process3", &ServerTest::process3);

        //-------------------------------------------------------------------------------------
    }



    void manipulate(const std::string& func,char* strBuffer)
    {
        auto it = m_mFuncPtr.find(func);

        if (it == m_mFuncPtr.end() || nullptr == it->second)
        {
            return;
        }

        (this->*it->second)(strBuffer);

        measureVolume(strBuffer);
    }


    ~ServerTest() = default;

};


class ClientTest:public Test
{

private:

    typedef char* (ClientTest::* pFunc)(char*);

    std::map<std::string, pFunc> m_mFuncPtr;



    //-------------------------------------------------------------------------------------
    // ADD SOMETHING HERE...

    char* process1(char *strBuffer);

    char* process2(char *strBuffer);

    char* process3(char *strBuffer);





    //-------------------------------------------------------------------------------------


public:
    ClientTest()
    {
        auto map_insert = [&](std::string key, pFunc ptr)
        {
            m_mFuncPtr.emplace(std::make_pair(key, ptr));
        };
        //-------------------------------------------------------------------------------------
        map_insert("process1", &ClientTest::process1);

        map_insert("process2", &ClientTest::process2);

        map_insert("process3", &ClientTest::process3);

        //-------------------------------------------------------------------------------------
    }



    void manipulate(const std::string& func,char* strBuffer)
    {
        auto it = m_mFuncPtr.find(func);

        if (it == m_mFuncPtr.end() || nullptr == it->second)
        {
            return;
        }

        (this->*it->second)(strBuffer);

        measureVolume(strBuffer);
    }


    ~ClientTest() = default;

};



