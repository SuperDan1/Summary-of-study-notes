#include"AVL.h"

void AVLTree::AVLInsert(AVLNode *& root, int key)
{
	if (!root)
		root = new AVLNode(key);
	else if (key < root->val)
	{
		AVLInsert(root->left, key);
		if (root->bf == 1)
			LeftBalance(root);
		else if (root->bf == 0)
			root->bf = 1;
		else if (root->bf == -1)
			root->bf = 0;
	}
	else
	{
		AVLInsert(root->right, key);
		if (root->bf == -1)
			RightBalance(root);
		else if (root->bf == 0)
			root->bf = -1;
		else if (root->bf == 1)
			root->bf = 0;
	}
}

void AVLTree::PreOrder(AVLNode * root)
{
}

void AVLTree::Inorder(AVLNode * root)
{
}

void AVLTree::PostOrder(AVLNode * root)
{
}

AVLNode * AVLTree::AVLSearch(AVLNode * p, int key)
{
	return nullptr;
}

void AVLTree::L_Rotate(AVLNode*& p)
{
	AVLNode* R = p->right;
	p->right = R->left;
	R->left = p;
	p = R;
}

void AVLTree::R_Rotate(AVLNode*& p)
{
	AVLNode* L = p->left;
	p->left = L->right;
	L->right = p;
	p = L;
}

void AVLTree::LeftBalance(AVLNode *& p)
{
	AVLNode* L, *Lr;
	L = p->left;
	if (L->bf == 1)
	{
		p->bf = L->bf = 0;
		R_Rotate(p);
	}
	else if (L->bf == 0)
	{
		Lr = L->right;
	}
}

void AVLTree::RightBalance(AVLNode *& p)
{
	L_Rotate(p->right);
	R_Rotate(p);
}
