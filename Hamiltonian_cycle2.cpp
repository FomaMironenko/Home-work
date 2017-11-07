// Hamiltonian_cycle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct edge 
{
	int V1;
	int V2;
};

void Hamilton(int** adj_Matrix, int V, int s, int* &D)
{
	for(int i = 1; i <= V; i++)
		if((adj_Matrix[s][i] != 0) && (D[i-1] != 1)){
			D[i-1] = 1;
		Hamilton(adj_Matrix, V, adj_Matrix[s][i], D);
		}
	cout << s << " ";
}

int main()
{ 
	int V = 0; //количество вершин
	int E = 0; //количество рёбер
	int j = 1;
	cin>>V;
	cin>>E;
	cout<<endl;

	edge* list = new edge [E];

	for(int i = 0; i < E; i++)
	{
		cin>>list[i].V1>>list[i].V2;
		cout<<endl;
	}

	int* Func = new int[V];

	for(int i = 0; i < E; i++)
	{
		Func[list[i].V1-1]++;
		Func[list[i].V2-1]++;
	}

	int* D = new int[V];

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


	int x = 0;
	for(int i = 0; i < V; i++)
		for(int l = 0; l < V; l++)
			if(Func[i] == 1 || (Func[i] + Func[l] < V && i != l))
				x = 1;

	cout << 1 << " ";
	Hamilton(adj_Matrix, V, 1, D);

	return 0;
}


