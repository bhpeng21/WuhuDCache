#include "wuhuDc.h"

//test
// #include "md5.h"

//默认构造函数
wuhuDc::wuhuDc() = default;

//ip和sockfd初始化
wuhuDc::wuhuDc(string ip, int sockfd): ip(ip), sockfd(sockfd)
{
    expireTime = time(0) + heartbeatLen;
}

//ip、socket和heartbeatLen初始化
wuhuDc::wuhuDc(string ip, int sockfd, int heartbeatLen): ip(ip), sockfd(sockfd) , heartbeatLen(heartbeatLen)
{
    expireTime = time(0) + heartbeatLen;
}

wuhuDc::~wuhuDc()
{
}

//如果不存在则写入key
void wuhuDc::indexAdd(string key)
{
    if (indexExist(key) == 0)
    {
		int slot = MD5(key).s2i() % numslots;
		pair<string, int> kv = make_pair(key, slot);
		this->indexTable.insert(kv);
        return;
    }
    return;
}

//key值在索引表中是否存在
int wuhuDc::indexExist(string key)
{
    if (indexTable.find(key) == indexTable.end())
    {
        return 0;       //不存在
    }
    return 1;       //存在
}

//重置过期时间
void wuhuDc::setExpire()
{
    expireTime = time(0) + heartbeatLen;
    return;
}

//判断节点是否失去心跳,1为活着，0为挂掉
int wuhuDc::isAlive()
{
    if (expireTime > time(0))
    {
        return 1;
    }
    survival = 0;
    return 0;
}

//test
// int main()
// {
// 	cout << "wuhuqifi" << endl;
	
// 	system("pause");
// 	return 0;
// }