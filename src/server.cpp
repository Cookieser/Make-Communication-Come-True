#include <gmpxx.h>
#include "../include/socket.h"
#include "../include/Test.h"

using namespace std;



int main(int argc,char *argv[])
{
    CTcpServer TcpServer;
  
    if (TcpServer.InitServer(stoi(argv[1]))==false)
    {
        cout<< "TcpServer.InitServer("<<stoi(argv[1])<<") failed." <<endl;

         return -1;
    }else
    {
  	    cout<< "TcpServer.InitServer("<<stoi(argv[1])<<") success." <<endl;
    }

    while(1){
        if (TcpServer.Accept()==false)
        {
            printf("TcpServer.Accept() failed.\n");
    
            return -1;
        }
  
  
        if(fork()>0) continue;

        printf("Client(%s) has been Accepted\n",TcpServer.GetIP());

        char strbuffer[1024];

        int id = 1;

        string command = "";

        ServerTest test;

        while (true)
        {
            memset(strbuffer,0,sizeof(strbuffer));

            if (TcpServer.Read(strbuffer,300)==false) break;
    
            cout<<"---------------------------------------"<<endl;

            cout<<id<<":"<<endl;

            printf("ACCEPT：%s\n",strbuffer);
    
            //DO SOMETHING HERE AND CALL BACK
    
            command="process"+ to_string(id++);

            test.manipulate(command,strbuffer);
        
            printf("SEND：%s\n",strbuffer);

            cout<<"---------------------------------------"<<endl;

            cout<<endl;

            if (TcpServer.Write(strbuffer)==false) break;
        }

    printf("\n");

    exit(0);
    }
}
