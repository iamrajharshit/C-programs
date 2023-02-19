#include <stdio.h>
#include <stdlib.h>

#define MAX 5 //defining max= 5

// structure stack
struct stack
{   int top; // s.top to store the index values of the s.item[]
    int items[MAX]; //item array in struct which is our stack
};
// push function with parameters item (value) and pointer stack *s therefore will pass &s while calling
void push(int item, struct stack *s)
        { //as stack s is pointer, therefore conditions are used as pointing ->
    if(s->top==MAX-1) printf("Stack FULL");//if s pointing to top == max-1 stack full
    else s->items[++(s->top)]=item;// increment the top and push item in the location
}
//struct stack pointer is passed
void pop(struct stack *s){
    int deleted; //local variable deleted
    if(s->top==-1) printf("Stack Empty"); //if s pointer top ==-1 empty check
    deleted=s->items[(s->top)--]; //we pop the last item of the stack s and them we decrement the top
    printf("Deleted item=%d",deleted); // printing the popped item
/* how do I return it to main and print there the deleted item*/
}

void display(struct stack *s ){
    int i;
    if(s->top==-1) printf("Stack Empty"); //empty check
    for(i=0;i<=s->top;i++) //loop for printing the items of stack
    printf("%d\t",s->items[i]);
}

int main(){
    int ch,item;
    struct stack s;
    s.top=-1; //initiating s.top value to -1
    printf("Welcome to stack");
    while(1)  //while its ture and not exited
    {
        printf("\nPress:\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1://push operation asking the item to be pushed
                printf("Item to be pushed in stack:\n");
                scanf("%d",&item);
                push(item,&s); //passing address of the stack s as in function we have considered pointer stack
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

