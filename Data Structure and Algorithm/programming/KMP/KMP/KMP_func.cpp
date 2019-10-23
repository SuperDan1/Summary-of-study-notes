#include"KMP.h"

vector<int> getNext(const string s)
{
	int n = s.size();
	vector<int> next(n);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < n-1)
	{
		if (k == -1 || s[k] == s[j])
		{
			k++;
			j++;
			if (s[k] == s[j])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int KmpSearch(const string s, const string t)
{
	// 进行字符串模式匹配KMP算法，s是主串，t是模式串
	vector<int> next = getNext(t);
	int s_len = s.size();
	int t_len = t.size();

	int i = 0;
	int j = 0;

	while (i < s_len && j < t_len)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == t_len)
		return i - j;
	else
		return -1;
}