#include<memory>
#include <iostream>
#include <vector>
using namespace std;
vector <double> a(100);
void quickSort(double l, double r){
 double x = a[(r + l) / 2];
 double i = l;
 double j = r;
 while(i <= j){
    while(a[i] < x){
       i++;
    }
    while(a[j] > x){
       j--;
    }
    if(i <= j){
       swap(a[i], a[j]);
       i++;
       j--;
    }
 }
 if (i<r){
    quickSort(i, r);}
 if (l<j){
    quickSort(l, j);}
}
int main(){
 int n;
 int k;
 cin>>n>>k;
 for(int i = 0; i < n; i++){
    cin>>a[i];
 }
 quickSort(0, n-1);
 cout<<a[k - 1];
 return 0;
}
