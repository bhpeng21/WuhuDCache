#include "TcpClient.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("usage:./tcpclient ip port\n"); return -1;
  }

  CTcpClient TcpClient;
  // 向服务器发起连接请求
  if (TcpClient.ConnectToServer(argv[1], atoi(argv[2])) == false)
  {
    printf("connect(%s:%s) failed.\n",argv[1],argv[2]); close(TcpClient.m_sockfd);  return -1;
  }

  printf("connect ok.\n");
  char buf[1024];

  for (int ii=0;ii<10000;ii++)
  {
    // 从命令行输入内容。
    memset(buf,0,sizeof(buf));
    printf("please input:"); 
    // scanf("%s",buf);
    cin.getline(buf, sizeof(buf)); // 获取客户端输入  注意：此时用的是cin.getline()来获取输入，因为其它输入方式比如scanf、cin等输入不能带有空格
    // sprintf(buf,"1111111111111111111111ii=%08d",ii);

    if (write(TcpClient.m_sockfd,buf,strlen(buf)) <=0) // 将客户端输入发送到远程服务器中
    { 
      printf("write() failed.\n");  close(TcpClient.m_sockfd);  return -1; // 发送失败则关闭客户端
    }
		
    memset(buf,0,sizeof(buf));
    if (read(TcpClient.m_sockfd,buf,sizeof(buf)) <=0)  // 读取远程服务器响应
    { 
      printf("read() failed.\n");  close(TcpClient.m_sockfd);  return -1;  // 读取远程服务器响应失败
    }

    printf("recv:%s\n",buf);

    // close(TcpClient.m_sockfd); break;
  }
} 
