// graph_matching.cpp: определяет точку входа для консольного приложения.
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

	bool* used; 
	int* M; 


void chain_increace(int v)
{ 
	if(used[v] == 1) 
		return; 

	int max = 0;
	int	k = 0; 
	used[v] = 1; 

	for(int i = 0; i < V; i++) 
		if(adj_Matrix[v][i])
		{ 
			k++; 
			chain_increace(i); 
			if(max < M[i]) 
				max = M[i]; 
		} 

		if(k == 0) 
			M[v] = 0; 
		else M[v] = max + 1; 
} 



int main()
{ 

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


	M = new int[V]; 
	used = new bool[V]; 
	
	int max = -1;
	int	k; 
	int	temp; 

	for(int i = 0; i < V; i++) 
	chain_increace(i); 
		for(int i = 0; i < V; i++) 
			if(max < M[i])
			{ 
				max = M[i]; 
				k = i; 
			} 
	cout << endl << k << endl; 

	for(int i = 0; i < V; i++)
	{ 
		for(int l = 0; l < V; l++) 
			if(M[k] - M[l] == 1 && adj_Matrix[k][l]) 
				temp = l; 
		k = temp; 
		cout << k << "; "; 
		if(M[k] == 0) 
			break; 
	} 

	cin >> V;
	return 0; 
}

