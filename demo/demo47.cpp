

/*

基础客户端

*/
#include "../_freecplus.h"
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
  	  
	// THE CONTENT AND ACTION WILL BE WRITTEN BELOW
/*	
	int num=5;
	//1
	memset(strbuffer,0,sizeof(strbuffer));
        string s = "<bizcode>1</bizcode><num>" + to_string(num) + "</num>";
	cout << s << endl;
	
        snprintf(strbuffer,1000,s.c_str(),1,1);
        printf("发送：%s\n",strbuffer);
	//if (TcpClient.Write(strbuffer)==false) break;
	memset(strbuffer,0,sizeof(strbuffer));
    	//if (TcpClient.Read(strbuffer,20)==false) break;  
    	printf("接收：%s\n",strbuffer);
    	num=(int)(strbuffer[0]);
    	sleep(10);
    	
    	//2
    	num = num*7;
    	memset(strbuffer,0,sizeof(strbuffer));
        s = "<bizcode>2</bizcode><num>" + to_string(num) + "</num>";
	cout << s << endl;
	
        snprintf(strbuffer,1000,s.c_str(),2,2);
        printf("发送：%s\n",strbuffer);
	//if (TcpClient.Write(strbuffer)==false) break;
	memset(strbuffer,0,sizeof(strbuffer));
    	//if (TcpClient.Read(strbuffer,20)==false) break;  
    	printf("接收：%s\n",strbuffer);
    	num=(int)(strbuffer[0]);
    	
    	cout<<num<<endl;
    	
    	*/
	
	
  int num;
	
  for (int i=0;i<50;i++)   
  {
    memset(strbuffer,0,sizeof(strbuffer));
    
    string s = to_string(i);
    
    snprintf(strbuffer,1000,s.c_str());
    
    printf("SEND：%s\n",strbuffer);
    if (TcpClient.Write(strbuffer)==false) break;    

    memset(strbuffer,0,sizeof(strbuffer));
    if (TcpClient.Read(strbuffer,20)==false) break; 
     
    printf("Accept：%s\n",strbuffer);

    sleep(10);
  }


}

