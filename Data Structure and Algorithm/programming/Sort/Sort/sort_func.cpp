#include"sort_head.h"

// ��ӡvector
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
				// ���򽻻�
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
		// ע��j�ǴӺ���ǰѭ��
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
		// ��flagΪtrue˵���й����ݽ���������ֹͣѭ��
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
		// ���������ӱ�
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
		Msort(v, s, mid);                   // �������󲿷ֽ��й鲢����
		Msort(v, mid+1, t);                 // �������Ҳ��ֽ��й鲢����
		Merge(v, s, mid, mid+1, t);         // �ϲ��Ѿ��������������
	}
}

void Msort1(vector<int>& v, int s, int t)
{
	int n = v.size();
	if (s < t)
	{
		// stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ���
		for (int step = 2; step / 2 < n; step *= 2)
		{
			// ÿstep��Ԫ��һ�飬����ǰstep/2�ͺ�step/2��Ԫ�ؽ��кϲ�
			for (int i = 0; i < n; i += step)
			{
				int mid = i + step / 2 - 1;               // ��������Ԫ�ظ���Ϊstep/2
				if (mid + 1 < n)                            // �����������Ԫ����ϲ�
					Merge(v, i, mid, mid+1, min(i+step-1, n-1));
			}
		}
	}
}

void Merge(vector<int>& v, int l_s, int l_t, int r_s, int r_t)
{
	int i = l_s;                            // ��벿�ֵ���ʼλ��
	int j = r_s;                            // �Ұ벿�ֵ���ʼλ��
	int n = r_t - l_s + 1;                  // Ҫ�ϲ���Ԫ����Ŀ
	vector<int> temp(n);                    // ��������
	int k = 0;                              // �����������ʼλ��
	
	while (i <= l_t && j <= r_t)
	{
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	}

	// �������ʣ�ֱ࣬�ӷ��뵽����������
	while (i <= l_t)
		temp[k++] = v[i++];
	while (j <= r_t)
		temp[k++] = v[j++];

	// ����ԭʼ����Ԫ��
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
		// ��low��high֮������һ��Ϊ��
		// �������ֵpivot���Ǹ�������
		pivot = Partition(v, low, high);
		// �Ե��ӱ�ݹ�����
		QSort(v, low, pivot-1);
		// �Ը��ӱ�ݹ�����
		QSort(v, pivot + 1, high);
	}
}

int Partition(vector<int>& v, int low, int high)
{
	int pivotkey;
	// ���ӱ�ĵ�һ����¼�������¼
	pivotkey = v[low];
	// �ӱ�����˽������м�ɨ��
	while (low < high)
	{
		while (low < high && v[high] > pivotkey)
			high--;
		while (low < high && v[low] < pivotkey)
			low++;
		// ��������while�ҵ����ڵ�����ʱ��pivotkey��������ڸ�����ʱ��pivotkeyС��������������
		vector_swap(v, low, high);
	}
	// ������������λ��
	return low;
}

void HeapSort(vector<int>& v)
{
	int n = v.size();
	// ��vector������һ���󶥶�
	for (int i = n/2-1; i >= 0; i--)
		HeapAdjust(v, i, n-1);
	for (int i = n - 1; i >= 0; i--)
	{
		// ���Ѷ���¼�͵�ǰδ�����������е����һ����¼����
		vector_swap(v, 0, i);
		// ��ʣ���������µ���Ϊ�󶥶�
		HeapAdjust(v, 0, i-1);
	}
}


void HeapAdjust(vector<int>& v, int s, int m)
{
	// ��v[s:m]�г���v[s]�������ѵĶ���
	int temp = v[s];
	int child = 2 * s + 1;     // ����
	while (child <= m)
	{
		// �ҵ����Һ����нϴ�Ľ��
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
