#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T val;
	Node<T>* next;
};

// �������������ͻ��ɢ�б���
template <typename T>
class HashTable
{
private:
	 int capacity;                 // ɢ�б��������ѡ�������ȽϺ�
	Node<T>** ht;                       // ɢ�б���ŵ�������ı�ͷ
	int Hash(const T& key);               // ��ϣ����
public:
	HashTable(const int size);          // ���캯��
	~HashTable();                       // ��������
	bool Insert(const T key);             // ����Ԫ��
	bool Remove(const T key);             // ɾ��Ԫ��
	bool IsExisted(const T& key);         // Ԫ���Ƿ����
	void show_HashTable();              // ��ӡɢ�б�
};

template<typename T>
inline int HashTable<T>::Hash(const T & key)
{
	// �ó���������
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
		Node<T>* head = new Node<T>;            // �����ͷ��㣬���洢����
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
	Node<T>* p = ht[pos];              // ��ͷ��㣬���洢����
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
	Node<T>* p = ht[pos];              // ��ͷ��㣬���洢����
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
	Node<T>* p = ht[pos];              // ��ͷ��㣬���洢����
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
		cout << "index" << i << "��";
		p = ht[i]->next;
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
}
