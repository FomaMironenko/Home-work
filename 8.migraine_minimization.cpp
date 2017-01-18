

#include <iostream>

#include <cmath>

using namespace std;

int Migr_min(int N){
 int n=sqrt(N);
 N=N-n*n;
 if (N==0)
 return 1;
 return 1+Migr_min(N);
}
int main(){
 int N;
 cin>>N;
 cout<<4*Migr_min(N);
 return 0;
}




