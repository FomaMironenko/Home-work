#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int i;
    int j;
    for((i=2); (i<=n); i+=1)
    {
        for((j=i+1); (j<=n); j+=1)
        {
            if (arr[j]%arr[i]=0)
            delete int*arr[j];
        }

    }
    cout<<arr[n];
    return 0;

}
