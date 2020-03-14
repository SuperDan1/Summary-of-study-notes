#include"HashTable.h"

typedef int T;
int main()
{
	HashTable<T> hashTable(11);
	int n;
	cout << "请输入插入哈希表的个数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		hashTable.Insert(temp);
	}
	hashTable.show_HashTable();
	cout << "你想删除的数字：";
	int num;
	cin >> num;
	hashTable.Remove(num);
	hashTable.show_HashTable();
	system("pause");
	return 0;
}