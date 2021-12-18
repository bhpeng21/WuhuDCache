/*
 * TcpClient.cpp - client�ͻ������Ա����ʵ��
 * ���ߣ������� 
 * �汾 1.0
 * 2021/12/17
 */
#include"TcpServer.h"
CTcpServer::CTcpServer()
{
    // ���캯����ʼ��socket
    m_listenfd = m_clientfd = 0;
}

CTcpServer::~CTcpServer()
{
    if (m_listenfd != 0) close(m_listenfd);  // ���������ر�socket
    if (m_clientfd != 0) close(m_clientfd);  // ���������ر�socket
}

//���ܣ���ʼ������˵�socket
//���룺
//  ͨ�Ŷ˿�port
//�����
//  �����Ƿ��ʼ���ɹ�
bool CTcpServer::InitServer(int port)
{
    m_listenfd = socket(AF_INET, SOCK_STREAM, 0);  // ��������˵�socket

    // �ѷ��������ͨ�ŵĵ�ַ�Ͷ˿ڰ󶨵�socket��
    struct sockaddr_in servaddr;    // ����˵�ַ��Ϣ�����ݽṹ
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;  // Э���壬��socket�����ֻ����AF_INET
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // ������������ip��ַ
    servaddr.sin_port = htons(port);  // ��ͨ�Ŷ˿�
    if (bind(m_listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0)
    {
        close(m_listenfd); m_listenfd = 0; return false;
    }

    // ��socket����Ϊ����ģʽ
    if (listen(m_listenfd, 5) != 0) { close(m_listenfd); m_listenfd = 0; return false; }

    return true;
}
//���ܣ����տͻ�������
//���룺
//  ��
//�����
//  �����Ƿ���ճɹ�
bool CTcpServer::Accept()
{
    if ((m_clientfd = accept(m_listenfd, 0, 0)) <= 0) return false;

    return true;
}
//���ܣ������ַ������ݱ�
//���룺
//  �������ַ���ָ��buf, �ַ�������
//�����
//  �����Ƿ��ͳɹ���<=0Ϊ����ʧ��
int CTcpServer::Send(const void* buf, const int buflen)
{
    return send(m_clientfd, buf, buflen, 0);
}

//���ܣ������ַ������ݱ�
//���룺
//  �������ַ���ָ��buf, �ַ�������
//�����
//  �����Ƿ���ճɹ���<=0Ϊ����ʧ��
int CTcpServer::Recv(void* buf, const int buflen)
{
    return recv(m_clientfd, buf, buflen, 0);
}