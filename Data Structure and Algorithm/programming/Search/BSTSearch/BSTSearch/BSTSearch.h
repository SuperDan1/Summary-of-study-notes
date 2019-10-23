#pragma once
#ifndef BSTSEARCH
#define BSTSEARCH

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// �����ṹ
template <typename T>
struct Node
{
	T val;
	Node<T>* left;
	Node<T>* right;
	Node<T>(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
class BST
{
public:
	BST()
	{
		root = NULL;
	}
	~BST()
	{
		// delete root
	}
	void InsertBST(Node<T>*& root, const T key);                          // ������
	void CreateBST(vector<int> v);                                        // �������������
	Node<T>* BSTSearch(T key);                                            // ���ҽ��
	void DeleteBST(T key);                                                // ɾ�����
	void PreorderBST();                                                   // �������
	void InorderBST();                                                    // �������
	void PostorderBST();                                                  // �������
	void LevelorderBST();                                                 // �������
private:
	Node<T>* root = NULL;
	Node<T>* BSTSearch_p(Node<T>* root, T key);                             // ���ҽ��
	void DeleteBST_p(Node<T>* root, T key);                                 // ɾ�����
	void Delete(Node<T>* root);
	void PreorderBST_p(Node<T>* root);                                      // �������
	void InorderBST_p(Node<T>* root);                                       // �������
	void PostorderBST_p(Node<T>* root);                                     // �������
	void LevelorderBST_p(Node<T>* root);                                    // �������
};

template <typename T>
void BST<T>::InsertBST(Node<T>*& root, const T key)
{
	if (!root)
	{
		root = new Node<T>(key);
		return;
	}
	else if (key < root->val)
		InsertBST(root->left, key);
	else
		InsertBST(root->right, key);
}

template<typename T>
inline void BST<T>::CreateBST(vector<int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		InsertBST(root, v[i]);
	}
}

template<typename T>
inline Node<T>* BST<T>::BSTSearch(T key)
{
	return BSTSearch_p(root, key);
}

template <typename T>
Node<T>* BST<T>::BSTSearch_p(Node<T>* root, T key)
{
	if (!root)
		return NULL;
	if (key == root->val)
		return root;
	else if (root->val > key)
		return BSTSearch_p(root->left, key);
	else
		return BSTSearch_p(root->right, key);
}

template<typename T>
inline void BST<T>::DeleteBST(T key)
{
	DeleteBST_p(root, key);
}

template <typename T>
void BST<T>::DeleteBST_p(Node<T>* root, T key)
{
	if (!root)
		return;
	else
	{
		if (key == root->val)
			Delete(root);
		else if (key < root->val)
			DeleteBST_p(root->left, key);
		else
			DeleteBST_p(root->right, key);
	}
}

template<typename T>
inline void BST<T>::Delete(Node<T>* root)
{
	Node<T>* p = NULL;
	Node<T>* s = NULL;
	// �������յĻ���ֻ���ؽ�����������
	if (root->right == NULL)
	{
		p = root;
		root = root->left;
		delete p;
	}
	else if (root->left == NULL)
	{
		p = root;
		root = root->right;
		delete p;
	}
	else
	{
		p = root;
		s = root->left;
		while (s->right)
		{
			p = s;
			s = s->right;
		}
		// ��ʱsָ��ɾ����ֱ��ǰ��
		root->val = s->val;
		if (p != root)
			p->right = s->left;
		else
			p->left = s->left;
		delete s;
	}
}

template<typename T>
inline void BST<T>::PreorderBST()
{
	PreorderBST_p(root);
}

template<typename T>
inline void BST<T>::InorderBST()
{
	InorderBST_p(root);
}

template<typename T>
inline void BST<T>::PostorderBST()
{
	PostorderBST_p(root);
}

template<typename T>
inline void BST<T>::LevelorderBST()
{
	LevelorderBST_p(root);
}

template <typename T>
void BST<T>::PreorderBST_p(Node<T>* root)
{
	if (!root)
		return;
	cout << root->val << " ";
	PreorderBST_p(root->left);
	PreorderBST_p(root->right);
}

template <typename T>
void BST<T>::InorderBST_p(Node<T>* root)
{
	if (!root)
		return;
	InorderBST_p(root->left);
	cout << root->val << " ";
	InorderBST_p(root->right);
}

template <typename T>
void BST<T>::PostorderBST_p(Node<T>* root)
{
	if (!root)
		return;
	PostorderBST_p(root->left);
	PostorderBST_p(root->right);
	cout << root->val << " ";
}

template<typename T>
void BST<T>::LevelorderBST_p(Node<T>* root)
{
	if (!root)
		return;
	queue<Node<T>*> q;
	q.push(root);
	while (!q.empty)
	{
		Node<T>* temp;
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
}
#endif // !BSTSEARCH