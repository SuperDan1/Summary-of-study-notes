#ifndef __KMP_H__
#define __KMP_H__


#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(const string);

int KmpSearch(const string, const string);
#endif 