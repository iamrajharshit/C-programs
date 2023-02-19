#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top=-1;
int arr[MAX];

void push(int item)
{ if(top==MAX-1) printf("STACK FULL\n");
  arr[++top]=item;
}

void pop(){
    if(top==-1) printf("STACK EMPTY\n");
    int del;
    del=arr[top--];
    printf("Deleted item:%d",del);
}

void display(){
    if(top==-1) printf("STACK EMPTY\n");
    printf("STACK ITEMS are:\n");
    for(int i=0;i<=top;i++) printf("%d\t",arr[i]);
}

int main(){
    int item, ch;
    printf("STACK USING ARRAY\n");
    while(1){
        printf("Enter the choice:\n 1)Push\n2)Pop\n3)Display\n4)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the item to be pushed:");
                scanf("%d",&item);
                push(item);
                printf("%d item pushed\n",item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice\n");



        }

    }
}
