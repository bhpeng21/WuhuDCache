#pragma once
#include <iostream>
#include <map>
#include <list>
#include <boost/make_shared.hpp>

//boost::shared_ptr<Net<float> > net_;
using namespace std;

//template<typename string, typename string>
class LRUCache
{
private:
	int m_iMaxSize;
	list<string> m_listLru; // 保存Key的链表，维护访问顺序

	typedef pair<list<string>::iterator, string> MPair;
	typedef shared_ptr<MPair> PairPtr; //利用智能指针来避免内存泄漏
	//MPair* PairPtr;
	map<string, PairPtr> m_mapPair; // 保存Key在链表中的位置和Key对应的Value

public:

	// 默认构造
	LRUCache();

	// 有参构造
	LRUCache(int iMaxSize);

	// 判断双向链表中是否有待查询key
	bool Contain(string& key);

	// 获取key对应value值
	bool Get(string& key, string& val);

	// 更新或者将新K-V对插入到链表中
	bool Set(string key, string val);

	// 移除最久未被访问的K-V对
	bool Remove(string& key);


	//// 判断双向链表中是否有待查询key
	//bool Contain(string& key)
	//{
	//	auto iterFind = m_mapPair.find(key);
	//	if (iterFind == m_mapPair.end())
	//		return false;
	//	return true;
	//}

	//// 获取key对应value值
	//bool Get(string& key, string& val)
	//{
	//	auto iterFind = m_mapPair.find(key);
	//	if (iterFind == m_mapPair.end())
	//		return false;

	//	val = iterFind->second->second;

	//	//	访问后移至链表头部
	//	auto iterList = iterFind->second->first;
	//	m_listLru.erase(iterList);
	//	m_listLru.push_front(iterFind->first);
	//	iterFind->second->first = m_listLru.begin();

	//	return true;
	//}

	//// 更新或者将新K-V对插入到链表中
	//bool Set(string key, string val)
	//{
	//	if (Contain(key))
	//	{
	//		auto iterFind = m_mapPair.find(key);
	//		iterFind->second->second = val;
	//		auto iterList = iterFind->second->first;
	//		m_listLru.erase(iterList);
	//		m_listLru.push_front(iterFind->first);
	//		iterFind->second->first = m_listLru.begin();
	//		//Move2Head(szKey);
	//		//cout << "Modify the value of key:" << szKey << endl;
	//		return true;
	//	}

	//	//	在链表的头部插入
	//	m_listLru.push_front(key);
	//	auto iterFront = m_listLru.begin();
	//	PairPtr pairPtr = make_shared<MPair>(iterFront, val);
	//	m_mapPair.insert(make_pair(key, pairPtr));

	//	//	判断缓存容量是否超过最大值
	//	if (m_listLru.size() > m_iMaxSize)
	//	{
	//		//	移除最久未被访问元素
	//		auto myKey = m_listLru.back();
	//		this->Remove(myKey);
	//	}

	//	return true;
	//}

	//// 移除最久未被访问的K-V对
	//bool Remove(string& key)
	//{
	//	auto iterFind = m_mapPair.find(key);
	//	if (iterFind == m_mapPair.end()) return false;
	//	auto iterList = iterFind->second->first;
	//	m_listLru.erase(iterList);
	//	m_mapPair.erase(iterFind);

	//	//cout << "Remove key:" << szKey << endl;

	//	return true;
	//}

};