#include <iostream>

using namespace std;

int **put_snake(int **Snake, int n, int m) {
  int c = 1;
  int a = 1;
  int g;
  for (int j = 0; j < n; j++) {
    if (n/2 >= a)
      for (int i = 1 + j; i <= 1 + j; i++)
        for (int l = n - j; l >= 1 + j; l--) {
          Snake[i][l] = c;
          c++;
          g = Snake[i][l];
        }
        c = g + 1;
       if (m/2 >= a)
         for (int i = 2 + j; i <= m - j ; i++)
           for (int l = 1 + j; l <= 1 + j; l++) {
             Snake[i][l] = c;
               c++;
               g = Snake[i][l];
             }
           c = g;
           if (m/2 >= a)
           for (int i = m - j; i <= m - j ; i++)
             for (int l = 1 + j; l <= n - j; l++) {
               Snake[i][l] = c;
               c++;
               g = Snake[i][l];
             }
             c = g + 1;
             if (m/2 >= a)
               for (int i = m - 1 - j; i >= 2 + j ; i--)
                 for (int l = n - j; l <= n - j ; l++) {
                 Snake[i][l] = c;
                 c++;
                 g = Snake[i][l];
               }
               a++;
               c = g + 1;
               if (n - m == 0 && n%2 == 1)
                 Snake[n/2 + 1][m/2 + 1] = n * m;
   }
   return Snake;
}
int main() {
  int n;
  int m;
  cin>>n>>m;
  int **Snake = new int*[m];
  for (int i = 1; i <= n; i++)
    Snake[i] = new int[m];
    Snake = put_snake(Snake, n, m);
  for (int i = 1; i <= m; i++) {
    for (int l = 1; l <= n; l++) {
    cout<<Snake[i][l]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
