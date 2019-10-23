#include"BSTSearch.h"
typedef int T;

int main()
{
	vector<T> v = { 34, 18, 76, 13, 12, 11, 52, 82, 16, 67, 58, 73, 72 };
	BST<T> bst;
	int n = v.size();
	bst.CreateBST(v);
	Node<T>* p = bst.BSTSearch(17);
	bst.DeleteBST(76);
	bst.InorderBST();
	system("pause");
	return 0;
}