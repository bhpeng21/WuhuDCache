#include "utils.h"

//函数功能：判断输入字符串是否为正确格式

bool IsCommand(const string s) 
{
	//cout << "输入字符串为：" << s << endl;
	if (s.size() < 5) return false; // set或get占3个字符 空格占1个字符 k-v对至少为1个字符
	if (s[3] != ' ') return false;

	string str_command = s.substr(0, 3);
	
	if (str_command == "set")
	{
		int pos = s.find(' ', 4);
		if (pos != s.rfind(' ')) // 最后一个空格和第二个空格位置不相同
		{
			return false;
		}
		cout << "输入字符串为：" << s << endl;
		cout << "输入指令为：" << str_command << endl;
		cout << "输入key为：" << s.substr(4, pos-4) << endl;
		cout << "输入value为：" << s.substr(pos+1, s.length()-pos) << endl;
		return true;
	}
	else if (str_command == "get")
	{
		if (s.rfind(' ') != 3)
		{
			return false;
		}
		cout << "输入字符串为：" << s << endl;
		cout << "输入指令为：" << str_command << endl;
		cout << "输入key为：" << s.substr(4, s.length()-4) << endl;
		return true;
	}
	else return false;
	//cout << "输入指令为：" << str_command << endl;
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
		int pos = s.find(' ', 4);
		key = s.substr(4, pos - 4);
		val = s.substr(pos + 1, s.length() - pos);
	}
	else if (str_command == "get")
	{
		key = s.substr(4, s.length() - 4);
	}
}