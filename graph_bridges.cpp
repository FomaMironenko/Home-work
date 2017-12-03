// graph_bridges.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 

using namespace std; 

struct edge 
{
	int V1;
	int V2;
};
edge* list;

int** adj_Matrix; 

int timer = 0;

int V; //кол-во вершин
int E; //кол-во рёбер

int* fup; 
int* tin; 
int* used; 

int edges(int a, int b)
{ 
	for(int i = 0; i < E; i++) 
		if(((list[i].V1==a) && (list[i].V2==b))||((list[i].V1==b) && (list[i].V2==a))) 
	return i; 
} 

void dfs(int v, int p=-1)
{ 
	used[v] = 1; 
	tin[v] = fup[v] = timer++; 
	for(int i = 0; i < V; i++) 
		if(adj_Matrix[v][i])
		{ 
			int t0 = i; 
			if(t0 == p) 
				continue; 
			if(used[t0]) 
				fup[v] = min(fup[v], tin[t0]); 
			else
			{ 
				dfs(t0, v); 
				fup[v] = min(fup[v], fup[t0]); 
				if(fup[t0] > tin[v]) 
				cout << edges(v, t0) << " "; 
			} 
		} 
} 


int main()
{ 

	cin>>V;
	cin>>E;

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


tin = new int[V]; 
fup = new int[V]; 
used = new int[V]; 
dfs(0); 

	cin>>V;
	return 0; 
}
