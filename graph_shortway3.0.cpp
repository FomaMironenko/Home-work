// graph_001.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

	int V; //кол-во вершин
	int E; //кол-во рёбер

struct edge 
{
	int V1;
	int V2;
};


	int* vertex_dist = new int [V]; //расстояние от данной вершины до first
	int **adj_Matrix;




	void shortway(int first, int last)
	{
		vertex_dist[first-1] = 0;
		while(vertex_dist[last-1] == E + 1)
			for(int i = 0; i < V; i++)
				for(int j = 0; j < V; j++)
				{
					if((adj_Matrix[i][j] == 1) && (vertex_dist[i] > vertex_dist[j] + 1))
						vertex_dist[i] = vertex_dist[j] + 1;
				}
	}

	
	void way(int first, int last)
	{
		cout<<last;
		if(first == last)
			return ;
		for(int i = 0; i < V; i++)
			if((vertex_dist[last-1] == vertex_dist[i] - 1) && (adj_Matrix[last-1][i] == 1))
				way(first, i);
	}

	

int main()
{

	cin>>V;
	cin>>E;
	cout<<endl;

	for(int i = 0; i < V; i++)
	{
		vertex_dist[i] = E + 1;
	}

	edge* list = new edge [E];
	for(int i = 0; i < E; i++)
	{
		cin>>list[i].V1>>list[i].V2;
		cout<<endl;
	}


	//матрица смежности
	adj_Matrix = new int *[V];
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

	int f;
	int l;
	cout<<"enter vertex_distexes numbers";
	cin>>f;
	cin>>l;

	shortway(f, l);
	way(f, l);

	cin>>V;

	return 0;
}
