/*
 * TcpClient.cpp - client�ͻ������Ա����ʵ��
 * ���ߣ������� 
 * �汾 1.0
 * 2021/12/17
 */
#pragma once

#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

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

#endif