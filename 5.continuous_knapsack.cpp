#include <iostream>

using namespace std;

int main()
{
    double V;
    cin>>V;
    int n;
    cin>>n;
    double *w=new double[n];
    double *c=new double[n];
    double *k=new double[n];
    for(int i=0; i<n;i++){
        cin>>w[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        k[i]=c[i]/w[i];
        int j=i;
        while((j>0)&&(k[j]>k[j-1])){
            double extra_k;
            double extra_w;
            double extra_c;
            extra_k =k[j];
            k[j]=k[j-1];
            k[j-1]=extra_k;
             extra_w =w[j];
             w[j]=w[j-1];
             w[j-1]=extra_w;
              extra_c =c[j];
              c[j]=c[j-1];
              c[j-1]=extra_c;
            j=j-1;

        }
    }
    cout<<endl;
    double cost;
    cost=0;
    double volume;
    volume=0;
        for(int i=0; i<n; i++){
               cost=cost+c[i];
               volume=volume+w[i];
               if (volume>V){
                cost=cost-c[i];
                }
        }
    cout<<cost;
    return 0;
}

