#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class CTcpServer
{
public:
    int m_listenfd;   // ��������ڼ�����socket
    int m_clientfd;   // �ͻ�����������socket

    CTcpServer();

    bool InitServer(int port);  // ��ʼ�������

    bool Accept();  // �ȴ��ͻ��˵�����

    // ��Զ˷��ͱ���
    int  Send(const void* buf, const int buflen);
    // ���նԶ˵ı���
    int  Recv(void* buf, const int buflen);

    ~CTcpServer();
};