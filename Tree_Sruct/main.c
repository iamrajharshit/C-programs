#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *left;
    char info;
    strct node *right;
}NODE;

void preorder(NODE *root){
    if (root)// root null or not null is the base condtions
    {
        printf("%c\n",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root){
    if(root){
        preorder(root->left);
        preorder(root->right);
        printf("%c\n",root->info);
    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
