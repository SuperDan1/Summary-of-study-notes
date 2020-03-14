#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 顺序表查找
int Sequential_Search(vector<int>&, int);
// 二分查找
int BinarySearch(vector<int>&, int);
// 二分查找优化
int BinarySearch2(vector<int>&, int);
// 斐波那契查找
int FibonacciSearch(vector<int>&, int);
int Fibonacci(int);