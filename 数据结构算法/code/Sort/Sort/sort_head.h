#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 打印vector
void vector_print(vector<int>);
// 交换vector中两个数字
void vector_swap(vector<int>&, int, int);
// 冒泡排序初级版
void BubbleSort0(vector<int>&);
// 冒泡排序
void BubbleSort(vector<int>&);
// 冒泡排序改进
void BubbleSort2(vector<int>&);
// 简单选择排序
void SelectSort(vector<int>&);
// 直接插入排序
void InsertSort(vector<int>&);
// 希尔排序
void ShellSort(vector<int>&);
// 归并排序
void MergeSort(vector<int>&);                            // 为了和其他排序方式接口统一而建立的函数
void Msort(vector<int>&, int, int);                      // 归并排序主函数（递归）
void Msort1(vector<int>&, int, int);                     // 归并排序主函数（迭代）
void Merge(vector<int>&, int, int, int, int);            // 合并函数
// 快速排序
void QuickSort(vector<int>&);                            // 为了和其他排序方式接口统一而建立的函数
void QSort(vector<int>&, int, int);                      // 快速排序主函数
int Partition(vector<int>&, int, int);                   // 分区，找到一个数的索引，前面的数比它小，后面的数比它大
// 堆排序
void HeapSort(vector<int>&);                             // 堆排序主函数
void HeapAdjust(vector<int>&, int, int);                 // 调整为大顶堆