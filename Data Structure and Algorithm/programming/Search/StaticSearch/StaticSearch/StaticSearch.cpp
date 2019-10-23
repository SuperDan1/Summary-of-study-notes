#include"StaticSearch.h"

int main()
{
	int a[] = { 0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(n);
	v.assign(&a[0], &a[n]);
	int result = FibonacciSearch(v, 62);
	if (result == -1)
		cout << "未找到关键字" << endl;
	else
		cout << "已找到关键字，位置是：" << result << endl;
	system("pause");
	return 0;
}