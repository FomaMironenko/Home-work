// graph_001.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct edge 
{
	int V1;
	int V2;
};

int main()
{
 
	int V; //кол-во вершин
	int E; //кол-во рЄбер

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



	//список смежности
	for(int i = 0; i < V; i++)
	{
		cout<<i+1<<": ";
		for(int j = 0; j < V; j++)
		{
			if(adj_Matrix[j][i] == 1)
				cout<<j+1<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;



	//ћатрица инцидентности
	int **inc_Matrix = new int *[E];
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

	cout<<"  ";
	for(int i = 1; i <= E; i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i = 0; i < V; i++)
	{
		cout<<i+1<<" ";
		for(int j = 0; j < E; j++)
		{
			cout<<inc_Matrix[j][i]<<" ";
		}
			cout<<endl;
	}


	cin>>V;
	return 0;
}