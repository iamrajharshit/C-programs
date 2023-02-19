#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue{
    int front;
    int back;
    int queue[MAX];
};

void enqueue(int item, struct queue *q)
{ if(q->front && q->back == -1) printf("QUEUE EMPTY");
    else if(q->front == q->back) printf("");

}

void dequeue(struct queue *q)
{

}

void display(struct queue *q)
{

}


int main( )
{   struct queue q;
    q.front= -1;
    q.back= -1;
    int item, ch;

}
