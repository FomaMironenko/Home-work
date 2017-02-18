#include <iostream>

using namespace std;

class Vector{
    int* Array;
    int Size;
    int Cap;
  public:
    Vector(int n){
        Array=new int[n];
        Size=n;
        Cap=0;
    }

    ~Vector(){
        delete Array;
    }

    int current_size(){
        return Cap;
    }

    void push(int a){
        if (Size <= Cap){
            append(Size*2);
            Size*=2;
        }
        Array[Cap]=a;
        Cap++;
    }

    int find(int a){
        int i = 0;
        while((a!=Array[i]) && (Array[i+1]!='\0'))
            i++;
        if(a == Array[i])
            return i;
        return -1;
    }

    void wipe(int a){
        for (int i=0; i<Cap; i++){
            if (Array[i] == a){
                for (int l=i; l < Cap-1; l++)
                    Array[l]=Array[l+1];
                Array[Cap-1]='\0';
                Cap--;
            }
        }
    }

    void append(int new_size){
        int* Array1=new int[new_size];
        for (int i=0; i<new_size; i++)
            Array1[i]=Array[i];
        Array = Array1;
    }

    int& operator[](const int i){
        int k=1;
        if((i<Cap+1) && (i>0))
             return Array[i-1];
        if (k == 1)
             return (Array[i%Cap]);
 return (Array[-i%Cap]);
 }
};

int main(){
    return 0;
}
