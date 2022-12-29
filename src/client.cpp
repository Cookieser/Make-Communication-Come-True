#include <gmpxx.h>
#include "../include/socket.h"
#include "../include/Test.h"

using namespace std;

int main(int argc,char *argv[])
{
  CTcpClient TcpClient;   
  
  if (TcpClient.ConnectToServer(argv[1],stoi(argv[2]))==false) 
  {
      cout <<"TcpClient.ConnectToServer("<< argv[1] << ":" << stoi(argv[2])<<") failed."<<endl;

      return -1;
  }
  else{
  
  	cout <<"TcpClient.ConnectToServer("<< argv[1] << ":" << stoi(argv[2])<<") success."<<endl;
  
  }

  	char strbuffer[1024];

  	memset(strbuffer,0,sizeof(strbuffer)); 
  	  
	// THE CONTENT AND ACTION WILL BE WRITTEN BELOW

    int num;

    ClientTest test;

    string command = "";
	
    for (int i=0;i<50;i++)
    {
      
        cout<<"---------------------------------------"<<endl;

        cout<<i+1<<":"<<endl;

        command="process"+ to_string(i+1);
    
        test.manipulate(command,strbuffer);

        printf("SEND：%s\n",strbuffer);

        if (TcpClient.Write(strbuffer)==false) break;

        memset(strbuffer,0,sizeof(strbuffer));

        if (TcpClient.Read(strbuffer,20)==false) break;
     
        printf("Accept：%s\n",strbuffer);

        cout<<"---------------------------------------"<<endl;

        cout<<endl;

    sleep(3);
  }


}

