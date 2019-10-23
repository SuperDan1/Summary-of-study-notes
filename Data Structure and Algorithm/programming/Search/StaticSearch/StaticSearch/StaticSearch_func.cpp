#include"StaticSearch.h"

int Sequential_Search(vector<int>& v, int key)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		if (v[i] == key)
			return i;
	}
	return -1;
}

int BinarySearch(vector<int>& v, int key)
{
	int n = v.size();
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int BinarySearch2(vector<int>& v, int key)
{
	int n = v.size();
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low)*(key - v[low]) / (v[high] - v[low]);
		if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int FibonacciSearch(vector<int>& v, int key)
{
	int n = v.size();
	int low = 0;
	int high = n - 1;
	int k = 0;
	// 计算n位于斐波那契数列的位置
	while ((n - 1) > Fibonacci(k) - 1)
		k++;
	// 将不满的数值补全
	for (int i = n; i <= Fibonacci(k) - 1; i++)
		v.push_back(v[n-1]);
	while (low <= high)
	{
		// 计算当前分隔的下标
		int mid = low + Fibonacci(k - 1) - 1;
		if (key < v[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (key > v[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid <= n - 1)
				return mid;
			else
				return n - 1;
		}
	}
	return -1;
}

int Fibonacci(int k)
{
	vector<int> F(k+2, 0);
	F[1] = 1;
	for (int i = 2; i <= k; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return F[k];
}