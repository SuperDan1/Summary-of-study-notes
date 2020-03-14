#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T val;
	Node<T>* next;
};

// 用拉链法解决冲突的散列表类
template <typename T>
class HashTable
{
private:
	 int capacity;                 // 散列表的容量，选择素数比较好
	Node<T>** ht;                       // 散列表：存放的是链表的表头
	int Hash(const T& key);               // 哈希函数
public:
	HashTable(const int size);          // 构造函数
	~HashTable();                       // 析构函数
	bool Insert(const T key);             // 插入元素
	bool Remove(const T key);             // 删除元素
	bool IsExisted(const T& key);         // 元素是否存在
	void show_HashTable();              // 打印散列表
};

template<typename T>
inline int HashTable<T>::Hash(const T & key)
{
	// 用除留余数法
	int value = key % capacity;
	return value;
}

template<typename T>
inline HashTable<T>::HashTable(const int size)
{
	capacity = size;
	ht = new Node<T> *[size];
	for (int i = 0; i < size; i++)
	{
		Node<T>* head = new Node<T>;            // 链表表头结点，不存储数据
		head->next = NULL;
		ht[i] = head;
	}
}

template<typename T>
inline HashTable<T>::~HashTable()
{
	Node<T> *p, *q;
	for (int i = 0; i < capacity; i++)
	{
		p = ht[i];
		while (p)
		{
			q = p;
			p = p->next;
			delete(q);
		}
	}
}

template<typename T>
inline bool HashTable<T>::Insert(const T key)
{
	int pos = Hash(key);
	Node<T>* p = ht[pos];              // 表头结点，不存储数据
	Node<T>* q = p->next;
	while (q != NULL && q->val != key)
	{
		p = q;
		q = q->next;
	}
	if (q != NULL)
	{
		cout << "key exists already";
		return false;
	}	
	else
	{
		q = new Node<T>;
		q->val = key;
		q->next = NULL;
		p->next = q;
		return true;
	}	
}

template<typename T>
inline bool HashTable<T>::Remove(const T key)
{
	int pos = Hash(key);
	Node<T>* p = ht[pos];              // 表头结点，不存储数据
	Node<T>* q = p->next;
	while (q != NULL && q->val != key)
	{
		p = q;
		q = q->next;
	}
	if (q != NULL)
	{
		p->next = q->next;
		delete q;
		return true;
	}
	else
	{
		cout << "key doesn't exist";
		return false;
	}
}

template<typename T>
inline bool HashTable<T>::IsExisted(const T & key)
{
	int pos = Hash(key);
	Node<T>* p = ht[pos];              // 表头结点，不存储数据
	Node<T>* q = p->next;
	while (q != NULL && q->val != key)
	{
		p = q;
		q = q->next;
	}
	if (q != NULL)
		return true;
	else
		return false;
}

template<typename T>
inline void HashTable<T>::show_HashTable()
{
	Node<T>* p;
	for (int i = 0; i < capacity; i++)
	{
		cout << "index" << i << "：";
		p = ht[i]->next;
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
}
