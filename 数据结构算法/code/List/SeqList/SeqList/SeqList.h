#pragma once
#include<iostream>
using namespace std;
const int MaxSize = 100;

template <typename T>
class SeqList
{
public:
	SeqList() { Length = 0; }              // �޲ι��캯��������һ���յ�˳���
	SeqList(T a[], int n);                 // �вι��캯��������һ������Ϊn��˳���
	~SeqList() {};                         // �յ���������
	int len() { return Length; }           // �������Ա���
	T get(int i);                          // ���ҵ�i��Ԫ��
	int locate(int value);                 // ����ֵΪvalue��Ԫ�����
	void insert(int i, T value);           // �ڵ�i��λ�ò���ֵΪx��Ԫ��
	T Delete(int i);                       // ɾ����i��Ԫ��
	void printList();                      // ��ӡ���Ա�
private:
	T data[MaxSize];                       // ���Ա��������
	int Length;                            // ���Ա�Ԫ�ظ���
};

template<typename T>
inline SeqList<T>::SeqList(T a[], int n)
{
	if (n > MaxSize) throw "n�������Ա�����";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	Length = n;
}

template<typename T>
inline T SeqList<T>::get(int i)
{
	if (i < 0 || i > Length - 1) throw "����λ�÷Ƿ�";
	else return data[i];
}

template<typename T>
inline int SeqList<T>::locate(int value)
{
	for (int i = 0; i < Length; i++)
	{
		if (data[i] == value)
			return i;
	}
	cout << "����ֵ������";
	return -1;
}

template<typename T>
inline void SeqList<T>::insert(int i, T value)
{
	if (i < 0 || i>Length) throw "����λ�÷Ƿ�";

	for (int j = Length - 1; j >= i; j--)
		data[j + 1] = data[j];
	data[i] = value;
	Length++;
}

template<typename T>
inline T SeqList<T>::Delete(int i)
{
	return T();
}

template<typename T>
inline void SeqList<T>::printList()
{
	for (int i = 0; i < Length; i++)
		cout << data[i] << endl;
}
