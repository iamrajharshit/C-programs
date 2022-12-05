//STACK USING ARRAY

/*


#include <stdio.h>
#define SIZE 10     //defining size value 10
                 
int stack[SIZE];    //array of size 10     
int top=-1;         //top will always point to top of the stack
// top=-1 as stack is not yet initialized
//next will define push and pop functions

//push()

//The steps for push operation are:
//Check if the ‘top’ is negative or not.
//If the ‘top’ is negative then make it 0 and put the ‘value’ in the element having 0 index in the array ‘stack’.
//If it is not then put the value in the element having index ‘top+1’ in the array ‘stack’ and increase the top by 1

void push(int value)
{

    if(top<SIZE -1){
        if(top<0){
            stack[0] =value;
            top=0;
        }
    
        else
        {
          stack[top+1]=value;
          top++;
        }
    }
    else
    {
       printf("Stackoverflow\n")
    }
}

//pop()

//In pop operation, we return the topmost element and then decrease
//the value of the ‘top’ by 1. That’s it.


int pop()
{
   if(top>=0)
   {
    int n = stack[top];
    top--;
    return n;
   }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}


int main()
{
    push();
    push();
    display();
    pop();
    display();
    return 0;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//STACK USING POINTERS TO AN ARRAY
*/















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include <stdio.h>
#include <stdlib.h>*/

//REC FIBO
/*int fib(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return (fib(n-1)+fib(n-2));
}

int main()
{   int n, fib_of_n;
    
    printf("enter a number\n");
    scanf("%d",&n);
    fib_of_n=fib(n);
    printf("%d",fib_of_n);

    return 0;
}
*/


//RECursive FACT
/*
int fact(int n){
    if ((n==0)||(n==1)) return 1;
    return (n*fact(n-1));
}

int main (){
    int n;
    scanf("%d",&n);
    
    int fact_n=(fact(n));
    printf("%d",fact_n);
}
*/



//RECursive TOH

/*void toh(int n, int A, int B, int C){
    //if(n==1) printf("move disk from %d to %d\n ", A,C);
    if(n>=1){
        toh(n-1,A,C,B); //moving n-1 blocks to B using C
        printf("move %d disk from %d to %d\n",n,A,C);
        toh(n-1,B,A,C); // moving n-1 blocks to C using A as auxilary 
        return ;
    }
}

int main (){
    int n=3;
    toh(3,1,2,3);
    return 0;
}
*/


/*
void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("Move a Disk from %d to %d\n",A,C);
        TOH(n-1,B,A,C);
    }
}  // Tower Of Hanoi for 4 Disks [You may change the Value of 4 to any number of Disks]
int main ()
{
    TOH(3,1,2,3);
    return 0;
}
*/

/*
// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char beg_rod, char end_rod, char aux_rod)
{
	if (n == 1)
	{
	printf("\n Move disk 1 from rod %c to rod %c", beg_rod, end_rod);
		return;
	}
	towerOfHanoi(n-1, beg_rod, aux_rod, end_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, beg_rod, end_rod);
	towerOfHanoi(n-1, aux_rod, end_rod, beg_rod);
}

int main()
{
	int n = 4; // Number of disks
	towerOfHanoi(n,'A','C','B'); // A, B and C are names of rods
	return 0;
}
*/
