#pragma once
#include<string>
#include<iostream>
using namespace std;

// ���Client�����ַ�����ʽ�Ƿ���ȷ
bool IsCommand(const string s);

// �����ַ�����ȡ����
string GetCommand(const string s);

// �����ַ�����ȡKV��Ϣ
void GetKV(const string s, string& key, string& val);