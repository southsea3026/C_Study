#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
//node type shape data, left and right pointers
typedef struct BinTrNode {
    TElement data;
    struct BinTrNode* left;
    struct BinTrNode* right;
} TNode;
TNode* root;

void init_tree() { root = NULL;}
int is_empty_tree() { return root == NULL;}
TNode* get_root() {return root;}

//create new node
TNode* create_tree(TElement val, TNode* l, TNode* r){
    TNode* n = (TNode*) malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}

void preorder(TNode* n) {
    if (n != NULL) {
        printf("[%c] ", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}
//reverse node
void reverse(TNode *n){
    if(n == NULL){
        return;
    }else{
        TNode* temp;
        reverse(n->left);
        reverse(n->right);

        temp = n->left;
        n->left = n->right;
        n->right = temp;
    }
}

void main(){
    TNode *b, *c, *d, *e, *f;

    init_tree();
    c = create_tree('C', NULL, NULL);
    d = create_tree('D', NULL, NULL);
    b = create_tree('B', c, d);
    f = create_tree('F', NULL, NULL);
    e = create_tree('E', NULL, f);
    root = create_tree('A', b, e);

    printf("\n  Pre-Order : "); preorder( root );
    printf("\n  Reversed Tree Pre-Order : "); reverse(root); preorder(root);
    printf("\n");
}
