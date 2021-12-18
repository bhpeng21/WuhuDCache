/*
 * TcpClient.cpp - client�ͻ������Ա����ʵ��
 * ���ߣ������� 
 * �汾 1.0
 * 2021/12/17
 */
#include "TcpClient.h"

CTcpClient::CTcpClient()
{
    m_sockfd = 0;  // ���캯����ʼ��m_sockfd
}

CTcpClient::~CTcpClient()
{
    if (m_sockfd != 0) close(m_sockfd);  // ���������ر�m_sockfd
}

//���ܣ����������������
//���룺
//  serverip-�����ipָ�룬portͨ�Ŷ˿�
//�����
//  �����Ƿ����ӳɹ�

bool CTcpClient::ConnectToServer(const char* serverip, const int port)
{
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0); // �����ͻ��˵�socket

    struct hostent* h; // ip��ַ��Ϣ�����ݽṹ
    if ((h = gethostbyname(serverip)) == 0)
    {
        close(m_sockfd); m_sockfd = 0; return false;
    }

    // �ѷ������ĵ�ַ�Ͷ˿�ת��Ϊ���ݽṹ
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);

    // �������������������
    if (connect(m_sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0)
    {
        close(m_sockfd); m_sockfd = 0; return false;
    }

    return true;
}
//���ܣ�����������ͱ���
//���룺
//  �������ַ�������ָ��buf, ���ĳ��� buflen
//�����
//  �����Ƿ��ͳɹ� ������ֵ<=0��˵������ʧ��
int CTcpClient::Send(const void* buf, const int buflen)
{
    return send(m_sockfd, buf, buflen, 0);
}

//���ܣ����ܷ���������
//���룺
//  �������ַ�������ָ��buf, ���ĳ��� buflen
//�����
//  �����Ƿ���ܳɹ� ������ֵ<=0��˵������ʧ��
int CTcpClient::Recv(void* buf, const int buflen)
{
    return recv(m_sockfd, buf, buflen, 0);
}