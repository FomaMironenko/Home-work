#include <iostream> 
using namespace std; 
struct node{ 
 int num; 
 string data; 
 node* left = NULL; 
 node* right = NULL; 
 int bal = 0; 
}; 
class string_dict{ 
 node* root; 
 void del_tree(node* n){ 
 if(n == NULL) 
 return; 
 del_tree(n->left); 
 del_tree(n->right); 
 delete n; 
 } 
 void l_round(node* n){ 
 n->bal = 0; 
 node* tmp = n->right; 
 node* tmp1 = n->right->left; 
 tmp->left = n; 
 tmp->left->right = tmp1; 
 tmp->bal++; 
 if(n == root) 
 root = tmp; 
 else re_n(root, n, tmp); 
 } 
 void r_round(node* n){ 
 n->bal = 0; 
 node* tmp = n->left; 
 node* tmp1 = n->left->right; 
 tmp->right = n; 
 tmp->right->left = tmp1; 
 tmp->bal--; 
 if(n == root) 
 root = tmp; 
 else re_n(root, n, tmp); 
 } 
 void re_n(node* r, node* n, node* h){ 
 if(r->right == n){ 
 r->right = h; 
 return; 
 } 
 if(r->left == n){ 
 r->left = h; 
 return; 
 } 
 if(r->data < n->data) 
 re_n(r->right, n, h); 
 else re_n(r->left, n, h); 
 } 
 int l_r(node* n){ 
 if(n->bal > 0) 
 return 1; 
 if(n->bal < 0) 
 return -1; 
 return 0; 
 } 
 int max_g(node* n){ 
 if(n == NULL) 
 return 0; 
 if(max_g(n->left) > max_g(n->right)) 
 return 1 + max_g(n->left); 
 else return 1 + max_g(n->right); 
 } 
 public: 
 string_dict(string a, int i){ 
 root = new node; 
 root->data = a; 
 root->num = i; 
 } 
 node* get(){ 
 return root; 
 } 
 void push(string a, int i, node* n){ 
 if(n == NULL){ 
 node* tmp = new node; 
 tmp->data = a; 
 tmp->num = i; 
 n = tmp; 
 return; 
 } 
 if(i < n->num){ 
 if(n->left == NULL){ 
 node* tmp = new node; 
 tmp->data = a; 
 tmp->num = i; 
 n->left = tmp; 
 n->bal++; 
 return; 
 } 
 int g = max_g(n->left); 
 push(a, i, n->left); 
 if(g != max_g(n->left)) 
 n->bal++; 
 if(n->bal > 1){ 
 if(l_r(n->left) == -1) 
 l_round(n->left); 
 r_round(n); 
 } 
 return; 
 } 
 if(n->right == NULL){ 
 node* tmp = new node; 
 tmp->data = a; 
 tmp->num = i; 
 n->right = tmp; 
 n->bal--; 
 return; 
 } 
 int g = max_g(n->right); 
 push(a, i, n->right); 
 if(g != max_g(n->right)) 
 n->bal--; 
 if(n->bal < -1){ 
 if(l_r(n->right) == 1) 
 r_round(n->right); 
 l_round(n); 
 } 
 return; 
 } 
 string pop(){ 
 if(root == NULL) 
 return "no element"; 
 node* tmp = root; 
 string a; 
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
 tmp->bal--; 
 tmp = tmp->left; 
 } 
 if(tmp->left->right != NULL){ 
 a = tmp->left->data; 
 node* tmp1 = tmp->left->right; 
 delete tmp->left; 
 tmp->left = tmp1; 
 tmp->bal--; 
 return a; 
 } 
 a = tmp->left->data; 
 delete tmp->left; 
 tmp->left = NULL; 
 tmp->bal--; 
 return a; 
 } 
 bool find(int i, node* n){ 
 if(n == NULL) 
 return 0; 
 if(n->num == i) 
 return 1; 
 if(n->num > i) 
 return find(i, n->left); 
 return find(i, n->right); 
 } 
 ~string_dict(){ 
 del_tree(root); 
 } 
}; 
int main(){ 
 return 0; 
}
