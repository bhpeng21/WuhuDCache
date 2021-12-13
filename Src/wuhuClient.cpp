#include "wuhuClient.h"

//默认构造函数
wuhuClient::wuhuClient() = default;

//ip、sockfd为输入的构造函数
wuhuClient::wuhuClient(string ip, int sockfd): ip(ip), sockfd(sockfd) {}

wuhuClient::~wuhuClient()
{
}

//写入指令缓冲区
void wuhuClient::wirteQuery(const string &query)
{
    querybuf.push_back(query);
    return;
}

//缓冲区中取指令
string wuhuClient::getQuery()
{
    return querybuf.front();
}

//删掉已取指令
void wuhuClient::removeQuery()
{
    querybuf.erase(querybuf.begin());
    return;
}

//写入回复缓冲区
void wuhuClient::wirteReply(const string &query)
{
    replybuf.push_back(query);
    return;
}

//回复缓冲区中取回复
string wuhuClient::getReply()
{
    return replybuf.front();
}

//删掉已取回复
void wuhuClient::removeReply()
{
    replybuf.erase(replybuf.begin());
    return;
}


//test
//int main()
//{
//	string s = "wuhiqifi";
//	cout << s << endl;
//	
//
//	wuhuClient cli("192.168.0.0", 7000);
//	cli.wirteQuery("set wuhuwuhu arhaarha");
//	cli.wirteQuery("get wuhuarha");
//	string s1 = cli.getQuery();
//	cout << s1 << endl;
//	cli.removeQuery();
//	string s2 = cli.getQuery();
//	cout << s2 << endl;
//
//
//	system("pause");
//	return 0;
//}