#pragma once
#include<iostream>
#include<vector>
using namespace std;

// 平衡二叉树的结点结构，增加了平衡因子bf

struct AVLNode
{
	int val;                           // 结点数据
	int bf;                            // 结点的平衡因子
	AVLNode *left, *right;             // 左右孩子指针
	AVLNode(int x) : val(x), bf(0), left(NULL), right(NULL) {}
};

class AVLTree
{
private:
	AVLNode* root;
	// 左旋操作
	void L_Rotate(AVLNode*& p);
	// 右旋操作
	void R_Rotate(AVLNode*& p);
	// 左平衡旋转处理
	void LeftBalance(AVLNode*& p);
	// 右平衡旋转处理
	void RightBalance(AVLNode*& p);

public:
	// 构造函数
	AVLTree() { root = NULL; }
	// 返回根结点
	AVLNode* getRoot() { return root; }
	// 插入结点
	void AVLInsert(AVLNode*& root, int key);
	// 先序遍历
	void PreOrder(AVLNode* root);
	// 中序遍历
	void Inorder(AVLNode* root);
	// 后序遍历
	void PostOrder(AVLNode* root);
	// 在AVL树中查找值为key的结点并返回该结点
	AVLNode* AVLSearch(AVLNode* p, int key);
	
};