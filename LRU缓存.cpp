#include<unordered_map>//��unordered_map֮ǰ����tr1������
using namespace std;//���ͬʱ��Ҫ���������ռ�

/*
����˫��������ϣ����н���
*/
// ����˫������ڵ�
struct DlinkedNode
{
    int key, value;
    DlinkedNode* prev;
    DlinkedNode* next;
    // ���캯��
    DlinkedNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkedNode(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    LRUCache(int capacity) // ���캯��
    {
        this->capacity = capacity;
        this->size = 0;
        this->head = new DlinkedNode();
        this->tail = new DlinkedNode();
        head->next = tail; // ͷ�����β���������
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        else
        {
            move2head(cache[key]);
            return cache[key]->value;
        }
    }

    void put(int key, int value)
    {
        if (!cache.count(key)) // �ؼ��ֽڵ㲻����
        {
            DlinkedNode* node = new DlinkedNode(key, value);
            cache.insert(pair<int, DlinkedNode*>(key, node));
            addNewnode(node);
        }
        else // �ؼ��ֽڵ����
        {
            DlinkedNode* node = new DlinkedNode(key, value);
            node->prev = cache[key]->prev;
            node->next = cache[key]->next;
            cache[key] = node;
            move2head(node);
        }
    }
    void move2head(DlinkedNode* node)
    {
        // ���ڵ��˫��������ȡ��
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // ���ڵ���뵽˫������head��head->next֮��
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void addNewnode(DlinkedNode* node)
    {
        // DlinkedNode* tmp = new DlinkedNode();
        // ���ڵ���뵽˫������head��head->next֮��
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        this->size++;
        if (size > capacity) // �������ڵ��ܽڵ�������������ɾ��β���
        {
            // tmp = tail->prev;
            // tmp->prev->next = tail;
            // tail->prev = tmp->prev;
            // std::cout << tmp->key << endl;
            // cache.erase(tmp->key);
            // delete tmp; // �����ڴ�й©
            // �ı�β���ָ��
            tail->prev->prev->next = tail;
            cache.erase(tail->prev->key);
            tail->prev = tail->prev->prev;
            this->size--;
        }
    }
private:
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* head; // ˫������ͷ���
    DlinkedNode* tail; // ˫������β���
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */