#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
// TCP�ͻ�����
class CTcpClient
{
public:
    int m_sockfd;

    CTcpClient();

    // ��������������ӣ�serverip-�����ip��portͨ�Ŷ˿�
    bool ConnectToServer(const char* serverip, const int port);
    // ��Զ˷��ͱ���
    int  Send(const void* buf, const int buflen);
    // ���նԶ˵ı���
    int  Recv(void* buf, const int buflen);

    ~CTcpClient();
};

