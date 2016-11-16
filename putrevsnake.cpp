#include <iostream>

using namespace std;

int **put_reverse_snake(int **Snake, int n, int m) {
 int c = n * m;
 int a = 1;
 int g;
 for (int i = 1; i <= m; i++)
   for (int l = 1; l <= n; l++)
     Snake[i][l] = 0;
     for (int j = 0; j < n; j++) {
       for (int i = 1 + j; i <= 1 + j; i++)
         for (int l = n - j; l >= 1 + j; l--) {
           if (Snake[i][l] == 0) {
             Snake[i][l] = c;
             c--;
             g = Snake[i][l];
           }
         }
         c = g - 1;
         for (int i = 2 + j; i <= m - j; i++)
           for (int l = 1 + j; l <= 1 + j; l++) {
             if (Snake[i][l] == 0) {
               Snake[i][l] = c;
               c--;
               g = Snake[i][l];
             }
           }
           c = g - 1;
           for (int i = m - j; i <= m - j; i++)
             for (int l = 1 + j; l <= n - j; l++) {
               if (Snake[i][l] == 0) {
                 Snake[i][l] = c;
                 c--;
                 g = Snake[i][l];
               }
             }
             c = g - 1;
             for (int i = m -1 - j; i >= 2 + j; i--)
               for (int l = n - j; l <= n - j; l++) {
                 if (Snake[i][l] == 0) {
                   Snake[i][l] = c;
                     c--;
                     g = Snake[i][l];
                 }
               }
               a++;
               c = g - 1;
          }
return Snake;
}
int main() {
 int n;
 int m;
 cin>>n>>m;
 int **Snake = new int*[n];
 for (int i = 1; i <= n; i++)
   Snake[i] = new int[m];
 Snake = put_reverse_snake(Snake, n, m);
 for (int i = 1; i <= m; i++) {
   for (int l = 1; l <= n; l++) {
     cout<<Snake[i][l] - 1<<" ";
   }
   cout<<endl;
 }
 return 0;
}
