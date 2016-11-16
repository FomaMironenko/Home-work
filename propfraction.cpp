#include <iostream>
using namespace std;
int proper_fraction(int n) {
 int g = 0;
 if (n < 0)
 n = -n;
 if (n == 0)
 return 0;
 for (int i = 2; i < n - 1; i++)
   for (int l = 2; l <= i; l++)
    if (n % l == 0 && i % l == 0)
      g++;
 return g * 2;
 }
int main() {
 int n;
 cin>>n;
 cout<<proper_fraction(n);
 return 0;
}
