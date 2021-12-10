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
		printf("请输入第%d个字符串数据报：", i);
		while (1)
		{
			cin.getline(buffer, sizeof(buffer));
			/*printf("输入数据报为：%s\n", buffer);*/
			if (!IsCommand(buffer))
			{
				printf("输入字符串格式错误，请重新输入:");
			}
			else break;
		}
		if (GetCommand(buffer) == "set")
		{
			GetKV(buffer, key, val);
			if (!myCache.Set(key, val))
			{
				cout << "加入到缓存中失败！" << endl;
			}
			else
			{
				cout << "加入到缓存成功！" << endl;
			}
			
		}
		else if (GetCommand(buffer) == "get")
		{
			GetKV(buffer, key, val);
			if (myCache.Get(key, val))
			{
				cout << "获取成功!键" << key << "对应的值为：" << val << endl;
			}
			else
			{
				cout << "获取失败！" << endl;
			}
		}
		
		//cin.get(buffer, 100);
		

	}
	return 0;
}