#include <iostream>

using namespace std;

void Sort(int b, int e, int *&I, int *&End){
	int l=b;
	int r=e;
	int dop=End[I[(l+r)/2]];
	while (l<=r){
		while (End[I[l]]<dop)
			l++;
		while (End[I[r]]>dop)
			r--;
		if (l<=r)
			swap(I[l++], I[r--]);
    }
	if (b<r)
		Sort(b, r, I, End);
	if (e>l)
		Sort(l, e, I, End);
}

int main(){
	int n;
	cin>>n;
	int *I = new int[n];
	int *start = new int[n];
	int *End = new int[n];
	int k=1;
	int p=0;
	for (int i=0; i<n; i++){
		cin>>start[i]>>End[i];
		I[i]=i;
	}
	Sort(0, n-1, I, End);
	for (int i=0; i<n; i++){
		if (start[I[i]]>=End[I[p]]){
			p=i;
			k=k+1;
		}
	}
	cout<<k;
	return 0;
}
