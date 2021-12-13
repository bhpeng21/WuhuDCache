#ifndef _WUHUDC_H_
#define _WUHUDC_H_

#include <unordered_map>
#include <vector>
#include <ctime>
#include <string>
//test-----wuhudc头文件和源文件中的string写成string
// #include <iostream>

using namespace std;

#define numslots 16384

class wuhuDc
{
private:
    string ip = "11";     //ip地址
    int sockfd = 0;     //socket
    unordered_map<string, int> indexTable;     //索引表
    int rehashidx = 0;      //缩扩容
    long long expireTime;   //心跳过期时间
    int heartbeatLen = 300;
    int survival = 1;       //心跳
public:
    wuhuDc();     //默认初始函数
    wuhuDc(string ip, int sockfd);      //构造函数，默认心跳最大时间
    wuhuDc(string ip, int sockfd, int heartbeatLen);        //构造函数，自定义心跳时间
    ~wuhuDc();
    void indexAdd(string key);
    int indexExist(string key);
    void setExpire();
	int isAlive();
};

#endif