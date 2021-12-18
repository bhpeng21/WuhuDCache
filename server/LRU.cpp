/*
 * TcpClient.h - client�ͻ����ඨ��
 * ���ߣ������� 
 * �汾 1.0
 * 2021/12/17
 */
#include "LRU.h"

// Ĭ�Ϲ���
LRUCache::LRUCache()
{

}


// �вι���
LRUCache::LRUCache(int iMaxSize)
{
	m_iMaxSize = iMaxSize;
}

// ���ܣ��ж�˫���������Ƿ��д���ѯkey
//���룺
//  ����ѯstring�ַ���key
//�����
//  �����Ƿ����
bool LRUCache::Contain(string& key)
{
	auto iterFind = m_mapPair.find(key);
	if (iterFind == m_mapPair.end())
		return false;
	return true;
}

//���ܣ���ȡkey��Ӧvalueֵ
//���룺
//  ����ѯ��string����keyֵ��Ҫ�洢��string����valueֵ
//�����
//  �����Ƿ��ȡ�ɹ�
bool LRUCache::Get(string& key, string& val)
{
	auto iterFind = m_mapPair.find(key);
	if (iterFind == m_mapPair.end())
		return false;

	val = iterFind->second->second;

	//	���ʺ���������ͷ��
	auto iterList = iterFind->second->first;
	m_listLru.erase(iterList);
	m_listLru.push_front(iterFind->first);
	iterFind->second->first = m_listLru.begin();

	return true;
}

//���ܣ���K-V�Բ��뵽˫��������
//���룺
//  �������string����keyֵ���������string����valueֵ
//�����
//  �����Ƿ����ɹ�
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

	//	�������ͷ������
	m_listLru.push_front(key);
	auto iterFront = m_listLru.begin();
	PairPtr pairPtr = make_shared<MPair>(iterFront, val);
	m_mapPair.insert(make_pair(key, pairPtr));

	//	�жϻ��������Ƿ񳬹����ֵ
	if (m_listLru.size() > m_iMaxSize)
	{
		//	�Ƴ����δ������Ԫ��
		auto myKey = m_listLru.back();
		this->Remove(myKey);
	}

	return true;
}

//���ܣ��Ƴ����δ�����ʵ�K-V��
//���룺
//  ��ɾ��K-V���е�string����keyֵ
//�����
//  �����Ƿ�ɾ���ɹ�
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
