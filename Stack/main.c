#include <stdio.h>
#include <stdlib.h>

#define MAX 5
//global


struct stack
{   int top;
    int items[MAX];
};

void push(int item, struct stack *s){
    if(s->top==MAX-1) printf("Stack FULL\n");
    else s->items[++(s->top)]=item;
}

void pop(struct stack *s){
    int deleted;
    if(s->top==-1) printf("Stack Empty\n");
    deleted=s->items[(s->top)--];
    printf("Deleted item=%d",deleted);

}

void display(struct stack *s ){
    int i;
    if(s->top==-1) printf("Stack Empty\n");
    for(i=0;i<= s->top;i++)
    printf("%d\t",s->items[i]);
}

int main(){
    int ch,item;
    struct stack s;
    s.top=-1;
    printf("Welcome to stack\n");
    while(1) {
        printf("\nPress:\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Item to be pushed in stack:\n");
                scanf("%d",&item);
                push(item,&s);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                exit(0);
            default:
                printf("wrong choice\n");
                break;
        }
    }
}

