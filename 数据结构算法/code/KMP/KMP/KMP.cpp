#include"KMP.h"

int main()
{
	string s = "abcabaaaabaabcac";
	string t = "abaabcac";
	int num = KmpSearch(s, t);
	if (num == -1)
		cout << "匹配失败";
	else
		cout << "匹配开始位置在主串的" << num << endl;
	system("pause");
	return 0;
}