#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ��ӡvector
void vector_print(vector<int>);
// ����vector����������
void vector_swap(vector<int>&, int, int);
// ð�����������
void BubbleSort0(vector<int>&);
// ð������
void BubbleSort(vector<int>&);
// ð������Ľ�
void BubbleSort2(vector<int>&);
// ��ѡ������
void SelectSort(vector<int>&);
// ֱ�Ӳ�������
void InsertSort(vector<int>&);
// ϣ������
void ShellSort(vector<int>&);
// �鲢����
void MergeSort(vector<int>&);                            // Ϊ�˺���������ʽ�ӿ�ͳһ�������ĺ���
void Msort(vector<int>&, int, int);                      // �鲢�������������ݹ飩
void Msort1(vector<int>&, int, int);                     // �鲢������������������
void Merge(vector<int>&, int, int, int, int);            // �ϲ�����
// ��������
void QuickSort(vector<int>&);                            // Ϊ�˺���������ʽ�ӿ�ͳһ�������ĺ���
void QSort(vector<int>&, int, int);                      // ��������������
int Partition(vector<int>&, int, int);                   // �������ҵ�һ������������ǰ���������С���������������
// ������
void HeapSort(vector<int>&);                             // ������������
void HeapAdjust(vector<int>&, int, int);                 // ����Ϊ�󶥶�