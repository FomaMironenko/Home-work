// graph_001.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

	int V; //���-�� ������
	int E; //���-�� ����
	int n = 0; //���-�� ��������� ���������

struct edge 
{
	int V1;
	int V2;
	bool ind; //��������� �� �� ���� �������
	int comp_adj;
};

	edge* list;
	int **inc_Matrix;

void adjacency(int q)	
{ 
	list[q].ind = true;
	list[q].comp_adj = n + 1;
	for(int t = 0; t < E; t++)
	{
		if(t == q)
			continue;
		if(((inc_Matrix[t][list[q].V1 - 1] == 1) || (inc_Matrix[t][list[q].V2 - 1] == 1)) && (!list[t].ind))
			adjacency(t);	
	}
}

int main()
{

	cin>>V;
	cin>>E;
	cout<<endl;

	list = new edge [E];

	for(int i = 0; i < E; i++)
	{
		cin>>list[i].V1>>list[i].V2;
		cout<<endl;
		list[i].ind = false;
		list[i].comp_adj = 0;
	}


	//������� �������������
	inc_Matrix = new int *[E];
	for(int i = 0; i < E; i++)
	{
		inc_Matrix[i] = new int [V];
	}

	for(int i = 0; i < E; i++)
		for(int j = 0; j < V; j++)
		{
			inc_Matrix[i][j] = 0;
			if((j+1 == list[i].V1)||(j+1 == list[i].V2))
				inc_Matrix[i][j] = 1;
		}


	
	//������ �� �����, ����� ��������� ���������
	for(int x = 0; x < E; x++)
		if(!list[x].ind)
		{
			adjacency(x);
			n++;
		}


	cout<<n;

	cin>>n;
	return 0;
}


