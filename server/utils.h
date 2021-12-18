/*
 * TcpClient.cpp - client�ͻ������Ա����ʵ��
 * ���ߣ������� 
 * �汾 1.0
 * 2021/12/17
 */
#pragma once

#ifndef _UTILS_H_
#define _UTILS_H_

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

#endif