#include <iostream>

using namespace std;

struct node{
  int data;
  node* next;
};

class Queue{
    node* head;
    public:

Queue(int a){
    head=new node;
    head->data=a;
    head->next=NULL;
}

~Queue(){
    while(head!=NULL){
    node* temp=head;
    head=head->next;
    delete temp;
}
}

void push(int a){
    node* temp=new node;
    temp->next=head;
    temp->data=a;
    head=temp;
}

int pop(){
    int a;
    node* temp=head;
    if (temp->next==NULL){
      a=temp->data;
      delete temp;
      return a;
    }
    while(temp->next->next!=NULL){
      int a=temp->next->data;
    }
    delete temp->next;
    temp->next=NULL;
    return a;
}
};

int main(){
}
