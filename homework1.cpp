#include <iostream>

using namespace std;
/*
GCD(int a, int b){
while((a!=0)&&(b!=0)){
    if(a>b) a=a%b;
    else b=b%a;
}
return a+b;
}*/

GCD(int a, int b){
    if (b==0) return a;
return GCD(b,a%b);}
int main()
{
    int a;
    int b;
   int d;
   cin>>a>>b;
   int c=a*b;
   d=c/GCD(a,b);
   cout<<d;
   return 0;
}
