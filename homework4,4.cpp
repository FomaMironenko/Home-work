#include <iostream>

using namespace std;

int f_euler_rec(int n)
{
  int i;
  int m=1;
  for (i=2; i <= n/2; i++)
      if (n % i == 0)
         {
         n/=i;
         while (n % i == 0)
           {
             m*=i;
             n/=i;
           }
         if (n==1) return m*(i-1);
         else return m*(i-1)*f_euler_rec(n);
         }
  return n-1;
}


int main()
{
   int n;
   cin>>n;
   cout<<f_euler_rec(n);
   return 0;
}
