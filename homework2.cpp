#include <iostream>

using namespace std;

int main()
{
 int a;
 int n;
 int i;
 int c;
 c=1;
 cin>>a;
 cin>>n;
 for((i=n); (i>=1); (i-=1))
    c=c*a;
 cout<<c;
 return 0;
}
