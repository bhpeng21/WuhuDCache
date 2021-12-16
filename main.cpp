#include<iostream>
#include<stdio.h>
#include"utils.h"
#include "LRU.h"
using namespace std;



int main()
{
	char buffer[1024];
	LRUCache<string, string> myCache(10);
	
	for (int i = 0; i < 3; i++)
	{
		string key;
		string val;
		printf("�������%d���ַ������ݱ���", i);
		while (1)
		{
			cin.getline(buffer, sizeof(buffer));
			/*printf("�������ݱ�Ϊ��%s\n", buffer);*/
			if (!IsCommand(buffer))
			{
				printf("�����ַ�����ʽ��������������:");
			}
			else break;
		}
		if (GetCommand(buffer) == "set")
		{
			GetKV(buffer, key, val);
			if (!myCache.Set(key, val))
			{
				cout << "���뵽������ʧ�ܣ�" << endl;
			}
			else
			{
				cout << "���뵽����ɹ���" << endl;
			}
			
		}
		else if (GetCommand(buffer) == "get")
		{
			GetKV(buffer, key, val);
			if (myCache.Get(key, val))
			{
				cout << "��ȡ�ɹ�!��" << key << "��Ӧ��ֵΪ��" << val << endl;
			}
			else
			{
				cout << "��ȡʧ�ܣ�" << endl;
			}
		}
		
		//cin.get(buffer, 100);
		

	}
	return 0;
}