#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int [n];
    for (int i=0; (i<n); i++){
        cin>>arr[i];
    }
   for(int i=0; (i<n); i++){
        for(int j=0; (j<i); j++){
            if (arr[j]==arr[i])
            for(int l=j+1; (l<n); l++){
                arr[l-1]=arr[l];
            //как удалить последние ненужные элементы массива?
            }
        }
   }
   for(int i=0; (i<n); i++){
    cout<<arr[i];
   }
   delete [] arr;
   return 0;
}
