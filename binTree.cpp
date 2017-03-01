#include <iostream>

#include <queue>

using namespace std;

struct node{
    int data;
    node*left = NULL;
    node*right = NULL;
};

class binaryTree{
    node*root;
   public:

binaryTree(int data){
    root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

void del_tree(node* n){
    if(n == NULL)
        return;
    del_tree(n->left);
    del_tree(n->right);
    delete n;
}

~binaryTree(){
    del_tree(root);
}

void push(int a, node*n){
    if(n==NULL){
        node*temp = new node;
        temp->data = a;
        temp->left = NULL;
        temp->right = NULL;
        n = temp;
        return;
    }
    if(n->left == NULL){
        node* temp = new node;
        temp -> data = a;
        temp -> left = NULL;
        temp -> right = NULL;
        n->left = temp;
        return;
    }
    if(n->right == NULL){
        node* temp = new node;
        temp->data = a;
        temp->left = NULL;
        temp->right = NULL;
        n->right = temp;
        return;
    }
    if(n->right->right != NULL)
        push(a, n->left);
        else push(a, n->right);
        return;
}

int pop(){
    if(root == NULL){
        cout << "ошибка";
        return 0;
    }
    node* temp = root;
    int a;
    if(temp->right == NULL){
        if(temp->left == NULL){
            a = temp->data;
            delete temp;
            root = NULL;
            return a;
        }
        a = temp->left->data;
        delete temp->left;
        root->left = NULL;
        return a;
    }
    while(temp->left->right != NULL){
        temp = temp->left;
    }
    if(temp->left->left != NULL){
        a = temp->left->left->data;
    delete temp->left->left;
    temp->left->left = NULL;
    return a;
    }
    if(temp->right->right != NULL){
        a = temp->right->right->data;
        delete temp->right->right;
        temp->right->right = NULL;
        return a;
    }
    if(temp->right->left != NULL){
        a = temp->right->left->data;
        delete temp->right->left;
        temp->right->left = NULL;
        return a;
    }
    if(temp->right != NULL){
        a = temp->right->data;
        delete temp->right;
        temp->right = NULL;
        return a;
    }
    a = temp->left->data;
    delete temp->left;
    temp->left = NULL;
    return a;
}

bool DFS(int data, node* n){
    if(n == NULL)
        return 0;
    if(n->data == data)
        return 1;
    if(DFS(data, n->left))
        return 1;
    if(DFS(data, n->right))
        return 1;
    return 0;
}

queue <node*>A;

bool BFS(int data){
    A.push(root);
    while(!A.empty()){
        node*temp = A.pop();
    if(temp->data == data)
        return 1;
    if(temp->left != NULL)
        A.push(temp->left);
    if(temp->right != NULL)
        A.push(temp->right);
    }
    return 0;
}
};

int main(){
}
