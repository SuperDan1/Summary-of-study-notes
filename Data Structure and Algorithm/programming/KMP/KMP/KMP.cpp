#include"KMP.h"

int main()
{
	string s = "abcdabd";
	string t = "abd";
	int num = KmpSearch(s, t);
	if (num == -1)
		cout << "ƥ��ʧ��";
	else
		cout << "ƥ�俪ʼλ����������" << num;
	system("pause");
	return 0;
}