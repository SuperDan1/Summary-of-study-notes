#include "Dijkstra.h"

Dijkstra::Dijkstra(int vexnum, int edge)
{
	// ��ʼ���������ͱ���
	this->vexnum = vexnum;
	this->edge = edge;
	// Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
	arc = new int*[this->vexnum];
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; i++)
	{
		arc[i] = new int[this->vexnum];
		for (int j = 0; j < this->vexnum; j++)
			arc[i][j] = INT_MAX;
	}
}

Dijkstra::~Dijkstra()
{
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++)
		delete this->arc[i];
	delete arc;
}

bool Dijkstra::check_edge_value(int start, int end, int weight)
{
	if (start < 1 || end < 1 || start > vexnum || end > vexnum || weight < 0)
		return false;
	return true;
}

void Dijkstra::createGraph()
{
	cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge)
	{
		cin >> start >> end >> weight;
		// �����жϱߵ���Ϣ�Ƿ�Ϸ�
		while (!this->check_edge_value(start, end, weight))
		{
			cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
			cin >> start >> end >> weight;
		}
		// ���ڽӾ����Ӧ�ϵĵ㸳ֵ
		arc[start - 1][end - 1] = weight;
		// ����ͼ������д���
		// arc[end - 1][start - 1] = weight;
		++count;
	}
}

void Dijkstra::print()
{
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			if (arc[i][j] == INT_MAX)
				cout << "��" << " ";
			else
				cout << arc[i][j] << " ";
		}
		cout << endl;
	}
}

void Dijkstra::Dijkstra_real(int begin)
{
	// ��ʼ��dis����
	for (int i = 0; i < this->vexnum; i++)
	{
		// ���õ�ǰ��·��
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	// ������㵽����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	int count = 1;
	// ����ʣ�ඥ������·��
	while (count != this->vexnum - 1)
	{
		// temp���浱ǰ���·�����±�
		// min�������·��ֵ
		int temp = 0;
		int min = INT_MAX;
		for (int i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit && dis[i].value < min)
			{
				temp = i;
				min = dis[i].value;
			}
		}
		// ��temp��Ӧ�Ķ�����뵽��֪�����·������
		dis[temp].visit = true;
		++count;
		for (int i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value)
			{
				//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
			}
		}
	}
}

void Dijkstra::print_path(int begin)
{
	string s;
	s = "v" + to_string(begin);
	cout << "��" << s << "Ϊ����ͼ�����·��Ϊ��" << endl;
	for (int i = 0; i < vexnum; i++)
	{
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else
			cout << dis[i].path << "�������·����" << endl;
	}
}
