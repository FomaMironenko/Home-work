#include <iostream> 
using namespace std; 
struct node{ 
 string data = "not"; 
 node* left = NULL; 
 node* right = NULL; 
 int col = 1; 
}; 
class rb_tree{ 
 node* root; 
 void del_tree(node* n){ 
 if(n == NULL) 
 return; 
 del_tree(n->left); 
 del_tree(n->right); 
 delete n; 
 } 
 void l_round(node* n){ 
 node* tmp = n->right; 
 node* tmp1 = n->right->left; 
 tmp->left = n; 
 tmp->left->right = tmp1; 
 tmp->col = 0; 
 tmp->left->col = 1; 
 if(n == root) 
 root = tmp; 
 else re_n(root, n, tmp); 
 } 
 void r_round(node* n){ 
 node* tmp = n->left; 
 node* tmp1 = n->left->right; 
 tmp->right = n; 
 tmp->right->left = tmp1; 
 tmp->col = 0; 
 tmp->right->col = 1; 
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
 int r_b(node* r, node* n){ 
 if(r->right == n) 
 if(r->left->col == 0); 
 return 1; 
 if(r->left == n) 
 if(r->right->col == 0); 
 return -1; 
 if(r->data < n->data) 
 return r_b(r->right, n); 
 else return r_b(r->left, n); 
 } 
 void g(node* n){ 
 n->left->col = 0; 
 n->right->col = 0; 
 if(n != root) 
 n->col = 1; 
 } 
 
 public: 
 rb_tree(string a){ 
 root = new node; 
 root->data = a; 
 root->col = 0; 
 root->left = new node; 
 root->left->col = 0; 
 root->right = new node; 
 root->right->col = 0; 
 } 
 node* get(){ 
 return root; 
 } 
 int size(node* n){ 
 if(n->data == "not") 
 return 0; 
 return 1 + size(n->left) + size(n->right); 
 } 
 void push(string a, node* n){ 
 if(n == NULL){ 
 root->data = a; 
 root->left = new node; 
 root->left->col = 0; 
 root->right = new node; 
 root->right->col = 0; 
 root->col = 0; 
 return; 
 } 
 if(a < n->data){ 
 if(n->left->data == "not"){ 
 node* tmp = new node; 
 tmp->data = a; 
 tmp->left = new node; 
 tmp->left->col = 0; 
 tmp->right = new node; 
 tmp->right->col = 0; 
 n->left = tmp; 
 return; 
 } 
 push(a, n->left); 
 if(n->left->col == 1){ 
 if(n->left->left->col == 1){ 
 if(n->right->col == 0) 
 r_round(n); 
 else g(n); 
 return; 
 } 
 if(n->left->right->col == 1){ 
 l_round(n->left); 
 if(n->right->col == 0) 
 r_round(n); 
 else g(n); 
 } 
 } 
 return; 
 } 
 if(n->right->data == "not"){ 
 node* tmp = new node; 
 tmp->data = a; 
 tmp->left = new node; 
 tmp->left->col = 0; 
 tmp->right = new node; 
 tmp->right->col = 0; 
 n->right = tmp; 
 return; 
 } 
 push(a, n->right); 
 if(n->right->col == 1){ 
 if(n->right->right->col == 1){ 
 if(n->left->col == 0) 
 l_round(n); 
 else g(n); 
 return; 
 } 
 if(n->right->left->col == 1){ 
 r_round(n->right); 
 if(n->left->col == 0) 
 l_round(n); 
 else g(n); 
 } 
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
 while(tmp->left->left != NULL) 
 tmp = tmp->left; 
 if(tmp->left->right != NULL){ 
 a = tmp->left->data; 
 node* tmp1 = tmp->left->right; 
 delete tmp->left; 
 tmp->left = tmp1; 
 return a; 
 } 
 a = tmp->left->data; 
 delete tmp->left; 
 tmp->left = NULL; 
 return a; 
 } 
 bool find(string a, node* n){ 
 if(n == NULL) 
 return 0; 
 if(n->data == a) 
 return 1; 
 if(n->data > a) 
 return find(a, n->left); 
 return find(a, n->right); 
 } 
 void slog(node* n){ 
 if(find(n->data, root) == 0) 
 push(n->data, root); 
 if(n->left->data != "not") 
 slog(n->left); 
 if(n->right->data != "not") 
 slog(n->right); 
 return; 
 } 
 ~rb_tree(){ 
 del_tree(root); 
 } 
}; 
int main(){ 
 return 0;
}
