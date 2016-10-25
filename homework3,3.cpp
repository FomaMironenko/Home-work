#include <iostream>

using namespace std;

int main()
{
int n;
int i;
int j;
cin >> n;
int *a = new int [n]; //задание массива из единиц
for (i = 0; i<n; i++) {
  a[i] = 1;
  };
for (i = 2; i<n; i++){ //проход по массиву со второго элемента и присваивание элемементам, номера которых кратны номеру данного значения 0
  if (a[i] == 1){
    for (j = i; j<n; j+=i){
      a[j] = 0;
      }
    a[i] = 1;
    }
  }
int q = 0;
for (int i = 2; i<n; i++){ //вывод номеров (i) элементов массива, равных 1 (номера - простые числа)
  if (a[i] == 1){
    cout  << i << " ";
    }
  }
delete [] a;
return 0;
}
