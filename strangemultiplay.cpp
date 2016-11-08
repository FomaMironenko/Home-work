#include "iostream"
using namespace std;

int strange_multiplay(int a, int b){
    int k=a;
for(int i=1; (i<b); i++){
    a+=k;
    }
    return a;
}

int main()
{
    int a;
    int b;
    cin>> a;
    cin>> b;
    cout<<strange_multiplay(a, b);
	return 0;
}

