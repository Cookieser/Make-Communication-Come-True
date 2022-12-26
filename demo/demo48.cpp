

/*

基础服务端

*/
#include "../_freecplus.h"
#include "../Test.h"
using namespace std;


/*

string func1(char *strBuffer){

    //string str= strBuffer;

    int num = atoi(strBuffer);
    num=num+10;

    string res= to_string(num);

    return res;
}
string func2(char *strBuffer){

    //string str= strBuffer;

    int num = atoi(strBuffer);
    num=num*10;

    string res= to_string(num);

    return res;
}

string func3(char *strBuffer){

    //string str= strBuffer;

    int num = atoi(strBuffer);
    num=num-13;

    string res= to_string(num);

    return res;
}
string func(int id,char *strBuffer) {
    string res=" ";
    switch (id) {
        case 1:
            cout << "---------------------------------" << endl;
            cout << "1:" << endl;
            res = func1(strBuffer);
            
            
      
            break;
        case 2:
            cout << "---------------------------------" << endl;
            cout << "2:" << endl;
            res = func2(strBuffer);
            
            
            
            break;
        case 3:
            cout << "---------------------------------" << endl;
            cout << "3:" << endl;
            res = func3(strBuffer);

            break;
        case 4:
            cout << "---------------------------------" << endl;
            cout << "4:" << endl;
            cout<<res<<endl;
            //res = func4(strBuffer);
    
            break;
    }

    return res;

}
*/

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
  Test test;

  while (true)
  {
    memset(strbuffer,0,sizeof(strbuffer));
    if (TcpServer.Read(strbuffer,300)==false) break; 
    
    cout<<"---------------------------------------"<<endl;
    cout<<id++<<":"<<endl;
    printf("ACCEPT：%s\n",strbuffer);
    
    //DO SOMETHING HERE AND CALL BACK
    
    command="process"+ to_string(id);
    
    

    test.manipulate(command,strbuffer);
    
    //string res= func(id,strbuffer);
    

    //sprintf(strbuffer,"%s",res.c_str());
    
    //strcat(strbuffer,"ok");  
        
    printf("SEND：%s\n",strbuffer);
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
    if (TcpServer.Write(strbuffer)==false) break;     
  }

  printf("\n");
  exit(0);    
}
}
