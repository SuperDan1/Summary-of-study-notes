#pragma once
#include<iostream>
#include<vector>
using namespace std;

// ƽ��������Ľ��ṹ��������ƽ������bf

struct AVLNode
{
	int val;                           // �������
	int bf;                            // ����ƽ������
	AVLNode *left, *right;             // ���Һ���ָ��
	AVLNode(int x) : val(x), bf(0), left(NULL), right(NULL) {}
};

class AVLTree
{
private:
	AVLNode* root;
	// ��������
	void L_Rotate(AVLNode*& p);
	// ��������
	void R_Rotate(AVLNode*& p);
	// ��ƽ����ת����
	void LeftBalance(AVLNode*& p);
	// ��ƽ����ת����
	void RightBalance(AVLNode*& p);

public:
	// ���캯��
	AVLTree() { root = NULL; }
	// ���ظ����
	AVLNode* getRoot() { return root; }
	// ������
	void AVLInsert(AVLNode*& root, int key);
	// �������
	void PreOrder(AVLNode* root);
	// �������
	void Inorder(AVLNode* root);
	// �������
	void PostOrder(AVLNode* root);
	// ��AVL���в���ֵΪkey�Ľ�㲢���ظý��
	AVLNode* AVLSearch(AVLNode* p, int key);
	
};