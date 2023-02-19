/*

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

typedef struct {
    char data[MAX_EXPR_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int peek(Stack *s) {
    return s->data[s->top];
}

void push(Stack *s, char c) {
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return -1;
}

void infix_to_postfix(char infix[], char postfix[], int size) {
    Stack s;
    init(&s);

    int i, j;
    for (i = 0, j = 0; i < size; i++) {
        if (isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            if (!is_empty(&s) && peek(&s) != '(') {
                return;
            } else {
                pop(&s);
            }
        } else {
            while (!is_empty(&s) && precedence(infix[i]) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_EXPR_SIZE], postfix[MAX_EXPR_SIZE];

    printf("Enter a valid parenthesized infix arithmetic expression: ");
    scanf("%s", infix);

    int size = strlen(infix);
    infix_to_postfix(infix, postfix, size);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

*/


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluate(char ch, int op1, int op2) {
    switch (ch) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        case '$': return pow(op1, (1/op2));
    }
    return -1;
}

int evaluatePostfix(char *exp) {
    int i;
    int op1, op2, value;

    for (i = 0; i < strlen(exp); i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            value = evaluate(exp[i], op1, op2);
            push(value);
        }
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a valid postfix expression: ");
    scanf("%s", exp);
    printf("Value of the expression: %d\n", evaluatePostfix(exp));
    return 0;
}

*/


/*
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Helper function to create a new tree node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// In-order traversal of the binary tree
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Post-order traversal of the binary tree
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Pre-order traversal of the binary tree
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\nPost-order traversal: ");
    postOrder(root);
    printf("\nPre-order traversal: ");
    preOrder(root);

    return 0;
}

 */


/*
 * //BTS
 *
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int maxValue(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

bool search(struct Node* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Maximum value: %d\n", maxValue(root));

    int searchValue = 60;
    if (search(root, searchValue))
        printf("Found %d in the tree\n", searchValue);
    else
        printf("Not found %d in the tree\n", searchValue);
    return 0;
}


 */

/*
// priority queue
#include <stdio.h>
#include <process.h>
#define size 5
void insert();
int del();
void dis();
int main(){
    int ch, item, rear=-1, front=0, q[10];
    for(;;){
        printf("1:Insert\n2:Del\n3:Dis\n4:Exit");
        printf("Enter the ch\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("item\n");
                scanf("%d",&item);
                insert(item,q,&rear);break;

            case 2:
                item=del(&front,&rear,q);
                if(item==-1) printf("queue empty\n");
                else
                printf("deleted= %d",item); break;

            case 3:
                dis(front,rear,q);break;

            case 4: exit(0); break;

            default:
                exit(0);
        }

    }
}

void insert(int item , int q[],int *r){
    int j=*r;
    if (*r== size-1){ printf("q empty\n"); return;}
    while(j>=0 && item< q[j]){
        q[j+1]=q[j];
        j--;
    }q[j+1]=item;
    *r=*r+1;
}

int del(int* front, int* rear ,int* q){
    if (*front >*rear) return -1;
    return q[*(front)++];
}

void dis(int front, int rear, int q[]){
    int i;
    if(front>rear){printf("Q empty\n"); return ;}
    printf("content:\n");
    for (i= front; i<= rear; i++){
        printf("%d\n",q[i]);
    }
}

*/



/*
//doubly linked list circular

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE first;
NODE getnode(){
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
void insert_f(int value){
    NODE temp=getnode();
    temp->data=value;
    if (first == NULL){
        first=temp;
        temp->left=first;
        temp->right=first;
    }
    else{
       NODE cur= first;
       while(cur->right!=first){
           cur=cur->right;
       }
       cur->right=temp;
       temp->right=first;
       temp->left=cur;
       first=temp;
    }
}

void del_r(){
    if(first==NULL){
        printf("list empty\n");
        return;
    }
    else{
        NODE cur,prev;
        cur=first;
        while(cur->right!=first){
            prev=cur;
            cur=cur->right;
        }
        prev->right=first;
        first->left=prev;
        cur->right=cur->left=NULL;
        free(cur);
    }
}



void dis(){
    NODE temp=first;
    if(first==NULL) {
        printf("list empty\n");
        return;
    }
    printf("contents are\n");
        while(temp->right!=first) {

            printf("%d\n", temp->data);
            temp = temp->right;
        }
        printf("%d\n",temp->data);
}



int main(){
    insert_f(12);
    insert_f(34);
    insert_f(45);
    dis();
    del_r();
    dis();
    return 0;
}

*/

/*
// doubly linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Pointer to the head of the list
struct Node* head = NULL;

// Function to insert a node at the front of the list
void insert_front(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL) {
        head->prev = new_node;
    }

    head = new_node;
}

// Function to delete a specified element from the list
void delete_element(int data) {
    struct Node* current = head;

    // Traverse the list to find the element
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    // If element not found
    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    // If element is the head
    if (current->prev == NULL) {
        head = current->next;
    } else {
        current->prev->next = current->next;
    }

    // If element is the tail
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

// Function to display the list
void display() {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to insert a node at a specified position
void insert_at(int data, int position) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;

    // Find the node at the specified position
    struct Node* current = head;
    int i;
    for (i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // If position is greater than the length of the list
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    // Insert the node at the specified position
    new_node->next = current->next;
    new_node->prev = current;
    current->next = new_node;

    if (new_node->next != NULL) {
n        new_node->next->prev = new_node;
    }
}

int main() {
    insert_front(1);
    insert_front(2);
    insert_front(3);
    display(); // Output: 3 2 1

    delete_element(2);
    display(); // Output: 3 1

    insert_at(4, 1);
    display(); // Output: 4 3 1

    return 0;
}
*/


/*
//Its FIBO
#include <stdio.h>
#include <stdlib.h>

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fibo(n - 1) + fibo(n - 2));

}

int main() {
    int i;
    int n;
    printf("Enter the number:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Fibo(%d)=%d\n", i, fibo(i));
    }
}

*/

/*
#include <stdio.h>

void fun1(int n)
{
    if (n > 0) {
        printf("%d\n", n);
        fun1(n-1);
        printf("rev %d\n",n);
    }
}

int main()
{
    int x = 3;
    fun1(3);

    return (0);
}

 */


/*
 *
 *
 * //traversals pre post in order
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Helper function to create a new tree node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// In-order traversal of the binary tree
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Post-order traversal of the binary tree
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Pre-order traversal of the binary tree
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\nPost-order traversal: ");
    postOrder(root);
    printf("\nPre-order traversal: ");
    preOrder(root);

    return 0;
}

*/


/*
#include <stdio.h>
#include <stdlib.h>
#include <minwindef.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int maxValue(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

BOOL search(struct Node* root, int data) {
    if (root == NULL) return FALSE;
    if (root->data == data) return TRUE;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Maximum value: %d\n", maxValue(root));

    int searchValue = 60;
    if (search(root, searchValue))
        printf("Found %d in the tree\n", searchValue);
    else
        printf("Not found %d in the tree\n", searchValue);
    return 0;
}

*/

/*
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main(void) {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) printf("Element is not present in array");
    printf("Element is present at index %d",result);
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluate(char ch, int op1, int op2) {
    switch (ch) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        case '$': return pow(op1, (1/op2));
    }
    return -1;
}

int evaluatePostfix(char *exp) {
    int i;
    int op1, op2, value;

    for (i = 0; i < strlen(exp); i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            value = evaluate(exp[i], op1, op2);
            push(value);
        }
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a valid postfix expression: ");
    scanf("%s", exp);
    printf("Value of the expression: %d\n", evaluatePostfix(exp));
    return 0;
}
