/*

#include <stdio.h>
#include <stdlib.h>



void enqueue(){};
void dequeue(){};

void levelorder(NODE* root){
    QUEUE q;
    enqueue(&q,root);
    NODE *n; //pointer to use it to enqueue and dequeue
    while(n!=dequeue(&q)){
        printf(n->data);
        enqueue(n->left);
        enqueue(n->right);
    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}

 */

/*

#include <stdio.h>

int main()
{
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i=1; i<=rows; ++i)
    {
        for(j=1; j<=i; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

*/


/*
//Daimond pattern

#include <stdio.h>

int main()
{
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i=1; i<=rows; i++)
    {
        for(j=1; j<=rows-i; j++)
            printf(" ");
        for(j=1; j<=2*i-1; j++)
            printf("*");
        printf("\n");
    }

    for(i=rows-1; i>=1; i--)
    {
        for(j=1; j<=rows-i; j++)
            printf(" ");
        for(j=1; j<=2*i-1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}

*/

//Inverted pyramid pattern:

/*
 #include <stdio.h>

int main()
{
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i=rows; i>=1; --i)
    {
        for(j=1; j<=i; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

*/


