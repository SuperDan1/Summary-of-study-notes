#include"sort_head.h"

int main()
{
	int a[] = {1, 9, 10, 5, 20, 50, 30, 100, 35, 45};
	vector<int> v(10);

	// ð�����������
	v.assign(&a[0], &a[10]);
	cout << "ð����������棺" << endl;
	BubbleSort0(v);
	vector_print(v);
	// ð������
	v.assign(&a[0], &a[10]);
	cout << "ð������" << endl;
	BubbleSort(v);
	vector_print(v);
	// ð������Ľ�
	v.assign(&a[0], &a[10]);
	cout << "ð������Ľ���" << endl;
	BubbleSort2(v);
	vector_print(v);
	// ��ѡ������
	v.assign(&a[0], &a[10]);
	cout << "��ѡ������" << endl;
	SelectSort(v);
	vector_print(v);
	// ֱ�Ӳ�������
	v.assign(&a[0], &a[10]);
	cout << "ֱ�Ӳ�������" << endl;
	InsertSort(v);
	vector_print(v);
	// ϣ������
	v.assign(&a[0], &a[10]);
	cout << "ϣ������" << endl;
	ShellSort(v);
	vector_print(v);
	// �鲢����
	v.assign(&a[0], &a[10]);
	cout << "�鲢����" << endl;
	MergeSort(v);
	vector_print(v);
	// ��������
	v.assign(&a[0], &a[10]);
	cout << "��������" << endl;
	QuickSort(v);
	vector_print(v);
	// ������
	v.assign(&a[0], &a[10]);
	cout << "������" << endl;
	HeapSort(v);
	vector_print(v);
	system("pause");
	return 0;
}