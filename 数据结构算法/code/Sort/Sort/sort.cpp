#include"sort_head.h"

int main()
{
	int a[] = {1, 9, 10, 5, 20, 50, 30, 100, 35, 45};
	vector<int> v(10);

	// √∞≈›≈≈–Ú≥ıº∂∞Ê
	v.assign(&a[0], &a[10]);
	cout << "√∞≈›≈≈–Ú≥ıº∂∞Ê£∫" << endl;
	BubbleSort0(v);
	vector_print(v);
	// √∞≈›≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "√∞≈›≈≈–Ú£∫" << endl;
	BubbleSort(v);
	vector_print(v);
	// √∞≈›≈≈–Ú∏ƒΩ¯
	v.assign(&a[0], &a[10]);
	cout << "√∞≈›≈≈–Ú∏ƒΩ¯£∫" << endl;
	BubbleSort2(v);
	vector_print(v);
	// ºÚµ•—°‘Ò≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "ºÚµ•—°‘Ò≈≈–Ú£∫" << endl;
	SelectSort(v);
	vector_print(v);
	// ÷±Ω”≤Â»Î≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "÷±Ω”≤Â»Î≈≈–Ú£∫" << endl;
	InsertSort(v);
	vector_print(v);
	// œ£∂˚≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "œ£∂˚≈≈–Ú£∫" << endl;
	ShellSort(v);
	vector_print(v);
	// πÈ≤¢≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "πÈ≤¢≈≈–Ú£∫" << endl;
	MergeSort(v);
	vector_print(v);
	// øÏÀŸ≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "øÏÀŸ≈≈–Ú£∫" << endl;
	QuickSort(v);
	vector_print(v);
	// ∂—≈≈–Ú
	v.assign(&a[0], &a[10]);
	cout << "∂—≈≈–Ú£∫" << endl;
	HeapSort(v);
	vector_print(v);
	system("pause");
	return 0;
}