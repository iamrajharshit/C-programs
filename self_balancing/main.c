#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef def struct node* NODE;

NODE getnode(){
    NODE x=(NODE)malloc(sizeof(struct node));
            return x;
}

NODE newnode( int data){
   NODE node=getnode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
}
void main() {
    printf("Hello, World!\n");

}
