#pragma once
#include<string>
#include<iostream>
#include"LRU.h"
#include "TcpClient.h"
using namespace std;

// ���Client�����ַ�����ʽ�Ƿ���ȷ
bool IsCommand(const string s);

// �����ַ�����ȡ����
string GetCommand(const string s);

// �����ַ�����ȡKV��Ϣ
void GetKV(const string s, string& key, string& val);

// �ַ������ݰ����Կͻ���
string PreClient(const string s, LRUCache& cache);

// �ַ������ݰ�����Master��
string PreMaster(const string s, LRUCache& cache, CTcpClient& clientfd);

// �ַ������ݰ�����cache server��
string PreCacheServer(const string s, LRUCache& cache);