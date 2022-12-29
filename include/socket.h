#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <netdb.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>



class CTcpClient
{
public:
  int  m_sockfd;
  char m_ip[21];
  int  m_port;
  bool m_btimeout;
  int  m_buflen;

  CTcpClient();


  bool ConnectToServer(const char *ip,const int port);

  bool Read(char *buffer,const int itimeout=0);

  bool Write(const char *buffer,const int ibuflen=0);

  void Close();

  ~CTcpClient();
};


class CTcpServer
{
private:

  int m_socklen;
  struct sockaddr_in m_clientaddr;
  struct sockaddr_in m_servaddr;

public:

  int  m_listenfd;
  int  m_connfd;
  bool m_btimeout;
  int  m_buflen;

  CTcpServer();


  bool InitServer(const unsigned int port); 

  bool Accept();

  char *GetIP();

  bool Read(char *buffer,const int itimeout);

  bool Write(const char *buffer,const int ibuflen=0);

  void CloseListen();

  void CloseClient();

  ~CTcpServer();
};


bool TcpRead(const int sockfd,char *buffer,int *ibuflen,const int itimeout=0);

bool TcpWrite(const int sockfd,const char *buffer,const int ibuflen=0);

bool Readn(const int sockfd,char *buffer,const size_t n);

bool Writen(const int sockfd,const char *buffer,const size_t n);
