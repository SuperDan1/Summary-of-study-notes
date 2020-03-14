#include"sort_head.h"

// 打印vector
void vector_print(vector<int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
}

void vector_swap(vector<int>& v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void BubbleSort0(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j])
			{
				// 大则交换
				vector_swap(v, i, j);
			}
		}
	}
}

void BubbleSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		// 注意j是从后往前循环
		for (int j = n-1; j > 0; j--)
		{
			if (v[j-1] > v[j])
			{
				vector_swap(v, j-1, j);
			}
		}
	}
}

void BubbleSort2(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		// 若flag为true说明有过数据交换，否则停止循环
		bool flag = false;
		for (int j = n - 1; j > 0; j--)
		{
			if (v[j - 1] > v[j])
			{
				vector_swap(v, j - 1, j);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

void SelectSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[min])
				min = j;
		}
		if (i != min)
			vector_swap(v, i, min);
	}
}

void InsertSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		int j;
		// 插入有序子表
		if (v[i] < v[i - 1])
		{
			int temp = v[i];
			for (j = i - 1; v[j] > temp; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = temp;
		}
	}
}

void ShellSort(vector<int>& v)
{
	int n = v.size();
	int increment = n;
	do
	{	
		increment = increment / 3 + 1;
		for (int i = increment; i < n; i++)
		{
			if (v[i] < v[i - increment])
			{
				int temp = v[i];
				int j;
				for (j = i - increment; j >= 0 && temp < v[j]; j -= increment)
				{
					v[j+increment] = v[j];
				}
				v[j + increment] = temp;
			}
		}
	} while (increment > 1);
}

void MergeSort(vector<int>& v)
{
	int n = v.size();
	Msort1(v, 0, n-1);
}

void Msort(vector<int>& v, int s, int t)
{
	if (s < t)
	{
		int mid = (s + t)/2;
		Msort(v, s, mid);                   // 对序列左部分进行归并排序
		Msort(v, mid+1, t);                 // 对序列右部分进行归并排序
		Merge(v, s, mid, mid+1, t);         // 合并已经有序的两个序列
	}
}

void Msort1(vector<int>& v, int s, int t)
{
	int n = v.size();
	if (s < t)
	{
		// step为组内元素个数，step/2为左子区间元素个数
		for (int step = 2; step / 2 < n; step *= 2)
		{
			// 每step个元素一组，组内前step/2和后step/2个元素进行合并
			for (int i = 0; i < n; i += step)
			{
				int mid = i + step / 2 - 1;               // 左子区间元素个数为step/2
				if (mid + 1 < n)                            // 右子区间存在元素则合并
					Merge(v, i, mid, mid+1, min(i+step-1, n-1));
			}
		}
	}
}

void Merge(vector<int>& v, int l_s, int l_t, int r_s, int r_t)
{
	int i = l_s;                            // 左半部分的起始位置
	int j = r_s;                            // 右半部分的起始位置
	int n = r_t - l_s + 1;                  // 要合并的元素数目
	vector<int> temp(n);                    // 辅助数组
	int k = 0;                              // 辅助数组的起始位置
	
	while (i <= l_t && j <= r_t)
	{
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	}

	// 如果还有剩余，直接放入到辅助数组中
	while (i <= l_t)
		temp[k++] = v[i++];
	while (j <= r_t)
		temp[k++] = v[j++];

	// 更新原始数组元素
	for (int i = 0; i < n; i++)
	{
		v[l_s+i] = temp[i];
	}
}

void QuickSort(vector<int>& v)
{
	int n = v.size();
	QSort(v, 1, n-1);
}

void QSort(vector<int>& v, int low, int high)
{
	int pivot;
	if (low < high)
	{
		// 将low到high之间数字一分为二
		// 算出枢轴值pivot（是个索引）
		pivot = Partition(v, low, high);
		// 对低子表递归排序
		QSort(v, low, pivot-1);
		// 对高子表递归排序
		QSort(v, pivot + 1, high);
	}
}

int Partition(vector<int>& v, int low, int high)
{
	int pivotkey;
	// 用子表的第一个记录作枢轴记录
	pivotkey = v[low];
	// 从表的两端交替向中间扫描
	while (low < high)
	{
		while (low < high && v[high] > pivotkey)
			high--;
		while (low < high && v[low] < pivotkey)
			low++;
		// 上述两个while找到了在低索引时比pivotkey大的数，在高索引时比pivotkey小的数，交换二者
		vector_swap(v, low, high);
	}
	// 返回枢轴所在位置
	return low;
}

void HeapSort(vector<int>& v)
{
	int n = v.size();
	// 将vector构建成一个大顶堆
	for (int i = n/2-1; i >= 0; i--)
		HeapAdjust(v, i, n-1);
	for (int i = n - 1; i >= 0; i--)
	{
		// 将堆顶记录和当前未经排序子序列的最后一个记录交换
		vector_swap(v, 0, i);
		// 将剩余数据重新调整为大顶堆
		HeapAdjust(v, 0, i-1);
	}
}


void HeapAdjust(vector<int>& v, int s, int m)
{
	// 在v[s:m]中除了v[s]外均满足堆的定义
	int temp = v[s];
	int child = 2 * s + 1;     // 左孩子
	while (child <= m)
	{
		// 找到左右孩子中较大的结点
		if (child < m && v[child] < v[child + 1])
			child++;
		if (temp < v[child])
		{
			v[s] = v[child];
			s = child;
			child = 2 * s + 1;
		}
		else
			break;
	}
	v[s] = temp;
}
