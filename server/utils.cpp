#include "utils.h"

//函数名称：判断输入字符串是否为正确格式

bool IsCommand(const string s) 
{
	//cout << "输入字符串为：" << s << endl;
	if (s.size() < 7) return false; // set或get占3个字符 两个空格占2个字符 k-v对至少为2个字符
	if (s[3] != ' ') return false;

	string str_command = s.substr(0, 3);
	
	if (str_command == "set")
	{
		if(s.size()!=11) return false; // 3+1+3+1+3
		if(s[3]==' '&&s[7]==' ') return true;
		else return false;
	}
	else if (str_command == "get")
	{
		
		if (s.find(' ') != 3 || s.size()!=7)
		{
			return false;
		}
		else return true;
	}
	
}

// 根据字符串提取命令
string GetCommand(const string s)
{
	return s.substr(0, 3);
}


// 根据字符串提取KV信息
void GetKV(const string s, string& key, string& val)
{
	string str_command = s.substr(0, 3);

	if (str_command == "set")
	{
		key = s.substr(4, 3);  // 这里默认key的长度为3
		val = s.substr(8, 3);  // 这里默认val的长度为3
	}
	else if (str_command == "get")
	{
		// key = s.substr(4, s.length() - 4);
		key = s.substr(4, 3);  // 这里默认key的长度为3
	}
}

// 字符串数据包来自客户端
string PreClient(const string s, LRUCache& cache)
{
	string res;
	string key,val;
	if(!IsCommand(s))
	{
		// strcpy(sendbuffer, "发送字符串数据包格式错误，请重新发送");
		res = "发送字符串数据包格式错误，请重新发送";
	}
	else
	{
		if (GetCommand(s) == "set")
		{
			GetKV(s, key, val);
			if (!cache.Set(key, val))
			{
				res = "加入到缓存中失败！";
			}
			else
			{
				// cout << "加入到缓存成功！" << endl;
				cache.Set(key, val);
				res = "加入到缓存中成功！";
			}
			
		}
		else if (GetCommand(s) == "get")
		{
			GetKV(s, key, val);
			if (cache.Get(key, val))
			{
				res = "获取成功，值为：" + val;

			}
			else
			{
				res = "获取失败！";
			}
		}
	}
	return res;
}

// 字符串数据包来自Master端
string PreMaster(const string s, LRUCache& cache, CTcpClient& TcpClient)
{
	char buf[1024];
	string strKV = "updateCache";
	string key;
	string val;
	string res;
	int num = (s.size()-23)/3;
	for(int i=0;i<num;i++)
	{
		key = s.substr(23+i*3, 3); // 关键字前字符串长度为：expand/narrow 6 + ip地址13 + 端口号4 = 23
		if(cache.Get(key, val))
		{
			strKV = strKV + key + val;
		}
	}
	strcpy(buf, strKV.c_str());
	if (write(TcpClient.m_sockfd,buf,strlen(buf)) <=0)
    { 
      printf("write() failed.\n");
	  res = "cache发送给另一个节点kV键值信息失败！";
	  close(TcpClient.m_sockfd);
	  return res;
    }
		
    memset(buf,0,sizeof(buf));
    if (read(TcpClient.m_sockfd,buf,sizeof(buf)) <=0) 
    { 
      printf("read() failed.\n");
	  res = "另一个节点kV返回cache确定信息失败！";
	  close(TcpClient.m_sockfd);
	  return res;
    }
	res = "扩容缩容成功！";
    // printf("recv:%s\n",buf);
	close(TcpClient.m_sockfd);
	return res;
}

// 字符串数据包来自cache server端
string PreCacheServer(const string s, LRUCache& cache)
{
	string res, key, val;
	int num = (s.size()-11)/6;
	for(int i=0;i<num;i++)
	{
		key = s.substr(11+i*6, 3);
		val = s.substr(14+i*6, 3);
		if (!cache.Set(key, val))
		{
			res = "加入到缓存中失败！";
		}
		else
		{
			// cout << "加入到缓存成功！" << endl;
			cache.Set(key, val);
			res = "加入到缓存中成功！";
		}
	}
	return res;
}

