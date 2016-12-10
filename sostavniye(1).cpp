#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a = new int [n];
    for(int i=0; (i<n); i++){
        cin>>a[i];
    }
    for(int i=0; (i<n); i++){
        int k;
        k=0;
        for(int j=2; (j<=(a[i]/2)); j++){
            if(a[i]%j==0){
                k=k+1;
                if(a[i]%(j*j)==0){
                    k=k+1;
                }
            }
        }
        if(k!=2){
            a[i]=1;
        }
    }
    int pr=1;
    for(int i=0; (i<n); i++){
        pr=pr*a[i];
    }
    cout<<pr;
    return 0;
}
