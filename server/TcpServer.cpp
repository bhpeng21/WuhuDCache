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

// ��ʼ������˵�socket��portΪͨ�Ŷ˿�
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

bool CTcpServer::Accept()
{
    if ((m_clientfd = accept(m_listenfd, 0, 0)) <= 0) return false;

    return true;
}

int CTcpServer::Send(const void* buf, const int buflen)
{
    return send(m_clientfd, buf, buflen, 0);
}

int CTcpServer::Recv(void* buf, const int buflen)
{
    return recv(m_clientfd, buf, buflen, 0);
}