#include "LRU.h"

// 默认构造
LRUCache::LRUCache()
{

}


// 有参构造
LRUCache::LRUCache(int iMaxSize)
{
	m_iMaxSize = iMaxSize;
}

// 判断双向链表中是否有待查询key
bool LRUCache::Contain(string& key)
{
	auto iterFind = m_mapPair.find(key);
	if (iterFind == m_mapPair.end())
		return false;
	return true;
}

// 获取key对应value值
bool LRUCache::Get(string& key, string& val)
{
	auto iterFind = m_mapPair.find(key);
	if (iterFind == m_mapPair.end())
		return false;

	val = iterFind->second->second;

	//	访问后移至链表头部
	auto iterList = iterFind->second->first;
	m_listLru.erase(iterList);
	m_listLru.push_front(iterFind->first);
	iterFind->second->first = m_listLru.begin();

	return true;
}

// 更新或者将新K-V对插入到链表中
bool LRUCache::Set(string key, string val)
{
	if (Contain(key))
	{
		auto iterFind = m_mapPair.find(key);
		iterFind->second->second = val;
		auto iterList = iterFind->second->first;
		m_listLru.erase(iterList);
		m_listLru.push_front(iterFind->first);
		iterFind->second->first = m_listLru.begin();
		//Move2Head(szKey);
		//cout << "Modify the value of key:" << szKey << endl;
		return true;
	}

	//	在链表的头部插入
	m_listLru.push_front(key);
	auto iterFront = m_listLru.begin();
	PairPtr pairPtr = make_shared<MPair>(iterFront, val);
	m_mapPair.insert(make_pair(key, pairPtr));

	//	判断缓存容量是否超过最大值
	if (m_listLru.size() > m_iMaxSize)
	{
		//	移除最久未被访问元素
		auto myKey = m_listLru.back();
		this->Remove(myKey);
	}

	return true;
}

// 移除最久未被访问的K-V对
bool LRUCache::Remove(string& key)
{
	auto iterFind = m_mapPair.find(key);
	if (iterFind == m_mapPair.end()) return false;
	auto iterList = iterFind->second->first;
	m_listLru.erase(iterList);
	m_mapPair.erase(iterFind);

	//cout << "Remove key:" << szKey << endl;

	return true;
}
