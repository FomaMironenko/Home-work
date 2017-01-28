#include <iostream>

using namespace std;

class String{
   public:
   char* lin;
   int n;
   String(char* a){
    for(n=0;a[n]!=0;n++){
      lin=new char[n];
    }
    for(int i=0; i<n;i++){
      lin[i]=a[i];
    }
   }
   ~String(){
    delete[] lin;
   }
   void set_i(int i, char a){
    lin[i] = a;
   }
   char get_i(int i){
    return lin[i];
   }
   int size_of(){
    return n;
   }
   void print(){
    for (int i = 0; i < n; i++){
     cout<<lin[i];
    }
   }
   void concat(String s){
    char* nil = new char[n+s.size_of()];
    for (int i = 0; i<n; i++){
     nil[i]=lin[i];
    }
    for (int i=n; i<n+s.size_of(); i++){
     nil[i]=s.get_i(i-n);
    }
    for (int i=0; i<n+s.size_of(); i++){
     cout<<nil[i]<<endl;
    }
   }
};

int main(){
return 0;
}

