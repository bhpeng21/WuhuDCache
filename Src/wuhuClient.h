#ifndef _WUHUCLIENT_H_
#define _WUHUCLIENT_H_

#include <string>
#include <vector>
//test
//#include <iostream>

using namespace std;

class wuhuClient
{
private:
    //ip地址、名字
    string ip; 

    //t套接字描述符
    int sockfd;

    //查询缓冲区域
    vector<string> querybuf;

    //回复链表
    vector<string> replybuf;

    //参数数量
    // int argc;
    //参数对象数组
    // string **argv;
    
    //客户端状态
    int flags = 1;

public:
    wuhuClient();
    wuhuClient(string ip, int sockfd);
    ~wuhuClient();
    //写入指令缓冲区
    void wirteQuery(const string &query);
    
    //缓冲区中取指令
    string getQuery();

    //删掉已取指令
    void removeQuery();
    
    //写入回复缓冲区
    void wirteReply(const string &query);

    //回复缓冲区中取回复
    string getReply();

    //删掉已取回复
    void removeReply(); 
}; 

#endif