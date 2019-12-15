#pragma warning(disable:4996)
#include<iostream>
using namespace std;

#include "mbd.h"

int main()
{
	int v1, v2;
	mbdModelClass mbd;
	mbd.initialize();
	cin >> v1 >> v2;
	mbd.mbd_U.In1 = v1;
	mbd.mbd_U.In2 = v2;

	mbd.step();
	cout << mbd.mbd_Y.Out1 << endl;
	system("pause");
	return 0;
}