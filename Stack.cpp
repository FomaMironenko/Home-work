#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

class Stack{

    node* head;
    public:

Stack(int a){
    head=new node;
    head->data=a;
    head->next=NULL;
}
void Push(int a){
    node* temp=new node;
    temp->next=head;
    temp->data=a;
    head=temp;
}
int Pop(){
    node* temp=head;
    int a=temp->data;
    head=head->next;
    delete temp;
    return a;
}
~Stack(){
    while(head!=NULL){
      node* temp=head;
      head=head->next;
      delete temp;
    }
}
};

int main(){
}
