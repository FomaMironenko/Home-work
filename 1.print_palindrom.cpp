#include <iostream>

using namespace std;

int po(int o,int p){
    int proizv;
    proizv=o;
    for(int i=1; i<=p-1;i++){
        proizv=proizv*o;
    }
    return proizv;
}
int main()
{
    int n;
    cin>>n;
    int c;
    for(c=po(10,n-1); c<=po(10,n)-1; c++){
        if (c%9==0){
            int prov;
            prov=1;
            for(int j=1; j<=n%2;j++){
                if((c%po(10,j)-c%po(10,j-1))!=(c/po(10,n-j)-10*(c/po(10,n-j+1)))){
                   prov=prov*0;
                }
                if (prov==1){
                    cout<<c;
                }
            }
        }
    }
}
