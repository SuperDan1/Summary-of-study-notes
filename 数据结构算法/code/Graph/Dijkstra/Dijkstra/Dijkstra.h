/************************************************************/
/*                �������ߣ�SuperDan                        */
/*                �������ʱ�䣺2019/4/16                   */
/*  Dijkstra���·���㷨ʵ�֣�����Ϊ����ͼ�����Ϊ���·��  */
/************************************************************/
#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ��¼��㵽ÿ����������·������Ϣ�����·��ֵ�����·�����Ƿ�visit��
struct Dis {
	string path;
	int value;
	bool visit;                      // visit=true��ʾ�Ѿ��ҵ����·���������ٴη���
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Dijkstra {
private:
	int vexnum;                      // ͼ�ж������
	int edge;                        // ͼ�бߵĸ���
	int **arc;                       // �ڽӾ���
	Dis *dis;                        // ��¼�����������·������Ϣ

public:
	// ���캯��
	Dijkstra(int vexnum, int edge);
	// ��������
	~Dijkstra();
	// �ж�ÿ������ıߵ���Ϣ�Ƿ�Ϸ�����Ŵ�1��ʼ
	bool check_edge_value(int start, int end, int weight);
	// ����ͼ
	void createGraph();
	// ��ӡ�ڽӾ���
	void print();
	// �����·��
	void Dijkstra_real(int begin);
	// ��ӡ���·��
	void print_path(int);
};