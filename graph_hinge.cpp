// graph_hinge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct edge 
{
	int V1;
	int V2;
};

int V; //кол-во вершин
int E; //кол-во рёбер

int** adj_Matrix;
int timer = 0;
int* fup;
int* tin;
int* used;

void dfs(int cur_v, int p=-1)
{
	used[cur_v] = 1;
	tin[cur_v] = fup[cur_v] = timer++;
	int children = 0;
	for(int i = 0; i < V; i++)
		if(adj_Matrix[cur_v][i])
		{
			int t0 = i;
			if(t0 == p)
				continue;
			if(used[t0])
				fup[cur_v] = min(fup[cur_v], tin[t0]);
			else
			{
				dfs(t0, cur_v);
				fup[cur_v] = min(fup[cur_v], fup[t0]);
				if(fup[t0] >= tin[cur_v] && p != -1)
					cout << cur_v << " ";
				children++;
			}
		}
	if(p == -1 && children > 1)
		cout << cur_v << " ";
}


int main()
{
	
	int V; //кол-во вершин
	int E; //кол-во рёбер

	cin>>V;
	cin>>E;
	cout<<endl;

	edge* list = new edge [E];

	for(int i = 0; i < E; i++)
	{
		cin>>list[i].V1>>list[i].V2;
		cout<<endl;
	}


	//матрица смежности
	int **adj_Matrix = new int *[V];
	for(int i = 0; i < V; i++)
	{
		adj_Matrix[i] = new int [V];
	}

	int tmp = V;
	bool flag = true;
	int l = 0;

	for(int i = V-1; i >= 0; i--)
		for(int j = 0; j < V; j++)
			adj_Matrix[i][j] = 0;


	for(int i = V-1; i >= 0; i--)
	{
		for(int j = 0; j < tmp; j++)
		{
			if(i != j)
			{
				flag = true;

				while(flag)
				{
					if(((list[l].V1 == i+1)&&(list[l].V2 == j+1))||((list[l].V1 == j+1)&&(list[l].V2 == i+1)))
					{
						adj_Matrix[i][j] = 1;
						adj_Matrix[j][i] = 1;
						flag = false;
					}
					l++;
					if(l > E-1)
						flag = false;
				}
				l = 0;
			}
		}
		tmp--;
	}

	cout<<"  ";
	for(int i = 1; i <= V; i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i = 0; i < V; i++)
	{
		cout<<i+1<<" ";
		for(int j = 0; j < V; j++)
		{
			cout<<adj_Matrix[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;


tin = new int[V]; 
fup = new int[V]; 
used = new int[V];

dfs(0);
return 0;
}