#include"HashTable.h"

typedef int T;
int main()
{
	HashTable<T> hashTable(11);
	int n;
	cout << "����������ϣ��ĸ�����";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		hashTable.Insert(temp);
	}
	hashTable.show_HashTable();
	cout << "����ɾ�������֣�";
	int num;
	cin >> num;
	hashTable.Remove(num);
	hashTable.show_HashTable();
	system("pause");
	return 0;
}