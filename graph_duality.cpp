// duality.cpp: определяет точку входа для консольного приложения.
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

	bool flag = 0; 
	int* num; 
	bool* used; 


	void dfs(int k, int c)
	{ 
		if(used[k] == 1)
		{ 
			if(c == num[k]) 
				flag = 1; 
				return; 
		} 
		used[k] = 1; 
		num[k] = (c + 1) % 2; 
		for(int i = 0; i < V; i++) 
			if(adj_Matrix[k][i] == 1) 
				dfs(i, num[k]); 
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

	
	num = new int[V]; 
	used = new bool[V]; 

	dfs(0, 0); 
	if(flag == 0) 
	for(int i = 0; i < V; i++) 
		cout << i << ": " << num[i] << "; "; 

	cin>>V;
	return 0; 
}



