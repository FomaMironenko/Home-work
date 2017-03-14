#include <iostream>

using namespace std;

struct node{
    int data;
    node*left = NULL;
    node*right = NULL;
    int bin = 0;
};

class bin_tree{
    node*root;
public:

    void del_tree(node*n){
        if(n == NULL)
        return;
        del_tree(n->left);
        del_tree(n->right);
        delete n;
    }

    void change(node*r, node*n, node*h){
        if(r->left == n){
            r->left = h;
            return;
        }
        if(r->right == n){
            r->right = h;
            return;
        }
        if(r == NULL)
            return;
            change(r->left, n, h);
            change(r->right, n, h);
            return;
    }

    int findout(node*n){
        if(n->bin > 0)
            return 1;
        if(n->bin < 0)
            return -1;
        return 0;
    }

    void left_turn(node*n){
        n->bin = 0;
        node*tmp = n->right;
        node*tmp1 = n->right->left;
        tmp->left = n;
        tmp->left->right = tmp1;
        tmp->bin = 1;
        if(n == root)
            root = tmp;
        else change(root, n, tmp);
     }

     void right_turn(node*n){
         n->bin = 0;
         node*tmp = n->left;
         node*tmp1 = n->left->right;
         tmp->right = n;
         tmp->right->left = tmp1;
         tmp->bin = -1;
         if(n == root)
             root = tmp;
         else change(root, n, tmp);
     }

    bin_tree(int a){
        root = new node;
        root->data = a;
    }

    node*get(){
        return root;
    }

    void push(int a, node* n){
        if(n == NULL){
            node*tmp = new node;
            tmp->data = a;
            n = tmp;
            return;
        }
        if(a < n->data){
            if(n->left == NULL){
                node*tmp = new node;
                tmp->data = a;
                n->left = tmp;
                n->bin++;
                return;
            }
            push(a, n->left);
            n->bin++;
            if(n->bin > 1){
                if(findout(n->left) == -1)
                    left_turn(n->left);
                    right_turn(n);
            }
            return;
        }
        if(n->right == NULL){
            node*tmp = new node;
            tmp->data = a;
            n->right = tmp;
            n->bin--;
            return;
        }
        push(a, n->right);
        n->bin--;
        if(n->bin < -1){
            if(findout(n->right) == 1)
                right_turn(n->right);
            left_turn(n);
        }
        return;
    }

    int pop(){
        if(root == NULL)
        return 0;
        node*tmp = root;
        int a;
        if(tmp->left == NULL){
            if(tmp->right == NULL){
                a = tmp->data;
                delete tmp;
                root = NULL;
                return a;
            }
            a = tmp->data;
            tmp = tmp->right;
            delete root;
            root = tmp;
            return a;
        }
        while(tmp->left->left != NULL){
            tmp->bin--;
            tmp = tmp->left;
        }
        if(tmp->left->right != NULL){
            a = tmp->left->data;
            node*tmp1 = tmp->left->right;
            delete tmp->left;
            tmp->left = tmp1;
            tmp->bin--;
            return a;
        }
        a = tmp->left->data;
        delete tmp->left;
        tmp->left = NULL;
        tmp->bin--;
        return a;
    }

    bool Find(int a, node*n){
        if(n == NULL)
            return 0;
        if(n->data == a)
            return 1;
        if(n->data > a)
            return Find(a, n->left);
        return Find(a, n->right);
    }

    ~bin_tree(){
        del_tree(root);
    }
};
int main(){
int a, b, c, d, e;
cin>>a>>b>>c>>d>>e;
bin_tree obj1(a);
obj1.push(b, obj1.get());
obj1.push(c, obj1.get());
obj1.push(d, obj1.get());
obj1.push(e, obj1.get());
cout<<obj1.Find(b, obj1.get())<<endl;
while(obj1.get() != NULL)
cout<<obj1.pop()<<endl;
return 0;
}
