// graph_DeBruijn.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"

using namespace std;

void edges(int** C, int max, int s, int** &D, int n)
{
	for(int i = 0; i < max; i++)
		if(C[s][i] != 0 && D[s][i] != 1){
			D[s][i] = 1;
			edges(C, max, i, D, n);
		}

	int h = 1;
	while(s >= n*h)
		h++;
	cout << s-n*(h-1) << " ";
}

int main()
{
	double n; //кол-во символов
	double k; //длина слова
	cin >> n >> k;

	int V = pow(n, k-1);
	int L = V / n;
	int** C = new int*[V];
	int** D = new int*[V];

	for(int i = 0; i < V; i++){
		C[i] = new int[V];
		D[i] = new int[V];
	}

	for(int i = 0; i < V; i++){
		int c = i - (i/L)*L;
		for(int l = 0; l < n; l++)
			C[i][c*(int)n+l] = 1;
	}

	for(int i = 0; i < V; i++){
		for(int l = 0; l < V; l++)
			cout << C[l][i] << " ";
		cout << endl;
	}

	edges(C, V, 0, D, n);

	return 0;
}