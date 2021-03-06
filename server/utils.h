#pragma once
#include<string>
#include<iostream>
#include"LRU.h"
#include "TcpClient.h"
using namespace std;

// 检查Client传送字符串格式是否正确
bool IsCommand(const string s);

// 根据字符串提取命令
string GetCommand(const string s);

// 根据字符串提取KV信息
void GetKV(const string s, string& key, string& val);

// 字符串数据包来自客户端
string PreClient(const string s, LRUCache& cache);

// 字符串数据包来自Master端
string PreMaster(const string s, LRUCache& cache, CTcpClient& clientfd);

// 字符串数据包来自cache server端
string PreCacheServer(const string s, LRUCache& cache);