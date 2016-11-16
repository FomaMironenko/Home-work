#include <iostream>
using namespace std;

int **dig_trench(int **Array, int size) {
   int g;
   for (int i = 1; i <= size; i++)
     for (int l = 1; l <= size; l++) {
       if (i >= l)
       g = i - l;
       else g = l - i;
       Array[i][l] = g;
     }
   return Array;
}

int main() {
   int n;
   cin>>n;
   int **trench = new int*[n];
   for (int i = 1; i <= n; i++)
     trench[i] = new int[n];
     trench = dig_trench(trench, n);
   for (int i = 1; i <= n; i++) {
     for (int l = 1; l <= n; l++) {
       cout<<trench[i][l]<<" ";
     }
     cout<<endl;
   }
 return 0;
}
