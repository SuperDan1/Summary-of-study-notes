#include"KMP.h"

int main()
{
	string s = "abcabaaaabaabcac";
	string t = "abaabcac";
	int num = KmpSearch(s, t);
	if (num == -1)
		cout << "ƥ��ʧ��";
	else
		cout << "ƥ�俪ʼλ����������" << num << endl;
	system("pause");
	return 0;
}