#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   int c;
   int d;
   cin>>a>>b;
   c=a*b;
   while((a!=0), (b!=0))
    if (a>b) a=a%b;
    else b=b%a;
   if (a>b) a=0;
    else b=0;
   d=c/(a+b);
   cout<<d;
   return 0;
}
