#include <iostream>

#include <vector>

using namespace std;

void  incredible_sort(int n, int k){
	vector <int> no(k);
	for(int i=0; i<n;++i){
		int numb;
		cin>>numb;
		no[numb - 1]++;
	}
	for(int i=k-1; i>=0;--i){
		if (no[i]!=0){
			for (int k = 0; k < no[i]; ++k){
				cout<< i+1<<" ";
			}
		}
	}
}
int main(){
	int n;
	int k;
	cin>>n>>k;
	incredible_sort(n,k);
	return 0;
}
