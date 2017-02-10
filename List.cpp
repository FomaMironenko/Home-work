#include <iostream>

using namespace std;

struct node{
   int data;
   node* next;
};

class List{
   node* head;
   public:

List(int a){
   head=new node;
   head->data=a;
   head->next=NULL;
}

~List(){
   while(head!=NULL){
      node* temp=head;
      head=head->next;
      delete temp;
   }
}

void Push_head(int a){
   node* temp=new node;
   temp->next=head;
   temp->data=a;
   head=temp;
}

void Push_back(int a){
   node* temp=head;
   while(temp->next!=NULL){
      temp=temp->next;
   }
   node* temp1=new node;
   temp->next=temp1;
   temp1->data=a;
   temp1->next=NULL;
}

void Push_data(int a, int data){
   node* temp=head;
   while(temp->data!=data){
      temp=temp->next;
   }
   node* temp1=new node;
   temp1->next=temp->next;
   temp1->data=a;
   temp->next=temp1;
}

int Get(int i){
   node* temp=head;
   for(int l=1; l<i; l++){
      temp=temp->next;
   }
   return temp->data;
}

int Size(){
   int a=1;
   node* temp=head;
   while (temp->next!=NULL){
      temp=temp->next;
   a++;
   }
   return a;
}

int Delete(int i){
   node* temp=head;
   int a;
   if(i==1){
      head=head->next;
      a=temp->data;
      delete temp;
      return a;
   }
   for(int l=1; l<i-1; l++){
      temp=temp->next;
   }
   a=temp->next->data;
   temp=temp->next->next;
   return a;
}

int Find(int a){
   node* temp=head;
   int i=1;
   while((a!=temp->data)&&(temp->next!=NULL)){
      temp=temp->next;
      i++;
   }
   if(a==temp->data){
      return i;
   }
   return 0;
}
};
