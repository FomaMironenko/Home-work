#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    cin>>n>>m;
    double *a = new double [n];
    double *b = new double [n];
    double *t = new double [m];
    int *k = new int [m];
     for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
        if(a[i]>b[i]){
            int d;
            d=a[i];
            a[i]=b[i];
            b[i]=d;
        }
        if((a[i]<=1000)&&(a[i]>=-1000)&&(b[i]<=1000)&&(b[i]>=-1000))
            continue;
        else
            break;
     }
    for(int i=1; i<=m;i++){
        k[i]=n;
    }
    for(int i=1; i<=m; i++){
        cin>>t[i];
        for(int j=1; j<=n; j++){
            if((t[i]<=b[j])&&(t[i]>=a[j]))
                k[i]=k[i]-1;
        }
    }
    for(int i=1; i<=m; i++){
        cout<<k[i]<<" ";
    }
}
