#include<unordered_map>//在unordered_map之前加上tr1库名，
using namespace std;//与此同时需要加上命名空间

/*
利用双向链表及哈希表进行解题
*/
// 创建双向链表节点
struct DlinkedNode
{
    int key, value;
    DlinkedNode* prev;
    DlinkedNode* next;
    // 构造函数
    DlinkedNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkedNode(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    LRUCache(int capacity) // 构造函数
    {
        this->capacity = capacity;
        this->size = 0;
        this->head = new DlinkedNode();
        this->tail = new DlinkedNode();
        head->next = tail; // 头结点与尾结点相连接
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
        if (!cache.count(key)) // 关键字节点不存在
        {
            DlinkedNode* node = new DlinkedNode(key, value);
            cache.insert(pair<int, DlinkedNode*>(key, node));
            addNewnode(node);
        }
        else // 关键字节点存在
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
        // 将节点从双向链表中取出
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 将节点插入到双向链表head与head->next之间
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void addNewnode(DlinkedNode* node)
    {
        // DlinkedNode* tmp = new DlinkedNode();
        // 将节点插入到双向链表head与head->next之间
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        this->size++;
        if (size > capacity) // 如果插入节点总节点数大于容量，删除尾结点
        {
            // tmp = tail->prev;
            // tmp->prev->next = tail;
            // tail->prev = tmp->prev;
            // std::cout << tmp->key << endl;
            // cache.erase(tmp->key);
            // delete tmp; // 避免内存泄漏
            // 改变尾结点指向
            tail->prev->prev->next = tail;
            cache.erase(tail->prev->key);
            tail->prev = tail->prev->prev;
            this->size--;
        }
    }
private:
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* head; // 双向链表头结点
    DlinkedNode* tail; // 双向链表尾结点
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */