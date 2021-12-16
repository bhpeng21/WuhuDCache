#pragma once
#include<string>
#include<iostream>
using namespace std;

// 检查Client传送字符串格式是否正确
bool IsCommand(const string s);

// 根据字符串提取命令
string GetCommand(const string s);

// 根据字符串提取KV信息
void GetKV(const string s, string& key, string& val);