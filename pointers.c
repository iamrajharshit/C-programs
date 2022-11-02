
// Working with Pointers!
#include <stdio.h>
int main()
{
    int a;
    int *p;
    a=10;
    p=&a; //&a = adress of a (assigned)
    printf("a=%d\n",a);
    printf("Address of p is %d\n",p);
    printf("Value at p is %d\n",*p);
    int b= 20;
    *p =b; // will the address in p change to point b??
    

    printf("Addresss of p  %d\n",p);
    printf("Value at p is %d\n",*p);
    return 0;
 
    //OUTPUT
    //Address of p is 3144576
    //Value at p is 10
    //Address  of P is 3144576
    //Value at p is 20

    //Here we see pointer is pointing towards variable a and still we can change the value of a using pointer variable.
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Pointer Arithmetic

#include<stdio.h>
int main()
{
    int a=10;
    int *p;
    p=&a;

    printf("Address of p is %d\n",p); //p is 2002
    printf("Value at address p is %d\n",*p); // value of a=10 
    printf("size of intefer is %d bytes\n",sizeof(int));
    printf("Address p+1 is %d\n",p+1);//p is 2006
    printf("Value at address p+1 is %d\n",*(p+1)); // garbage value no integer allocated to this memory address


   /*OUTPUT
    Address p is 4586052
    Value aat address p is 10
    size of integer is 4 bytes
    Address p+1 is 458056
    Value at address p+1 is -85895645*/

}

/////////////////////////////////////////////////////////////////////////////////////////////

// Pointer Types, Void pointer , pointer arithmetic
/* int - 4bytes
   char - 1bytes
   float - 4bytes*/

#include<stdio.h>
int main()
{
    int a=1025;
    int *p;
    p=&a;
    printf("Size of integer is %d",sizeof(int));
    printf("Address = %d, value = %d",p,*p);

    char *p0;
    p0 = (char*)p; // typecasting 
    printf("Size of char is %d bytes\n",sizeof(char));
    printf("Address = %d, value =%d\n",p0,*p0); // dereffrence p0 pointer to char
    //1025 = 00000000 00000000 00000100 00000001 (32 bits)


    //OUTPUT 
    /*Size od integer is 4 bytes
    Address= 2948664, value = 1025
    Size of char is 1 bytes
    Address = 2948664, value = 1 (why? value is 1) because being char it looks at byte0 i.e 00000001


    Doing same for p+1 *(p+1) and *p0 *(p0+1)
    */ 
}    

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//Void pointer - Genric pointer
void *p0;
p0=p;
printf("Address = %d",p0);
printf("Address= %d",p0+1);//will give compiler error


////////////////////////////////////////////////////////////////////////////////////////////////////////

//Pointer to Pointer

/*
& is for address


in memory we have data arranged lets take it as a horizontal column of 1byte.
int x=5;
int *p;
p=&x;
*p=6; 
int **q; //this pointer points to pointer 
q=&p;
int ***r=&q;
//derefrencing 
printf("%d\n",*p);
printf("%d\n",*q);    //is refring location
printf("%d\n",**q);   // is showing data stored in *p (derefrencing)
printf("%d\n",**r);   //** is showing location again
printf("%d\n",****r); //**** is showing data (derefrencing)
****r=10;
printf("x =%d\n",x);
**q = *p+2;
printf("x =%d\n",x);
//output
6
4193620
6
4193620
x = 10
x = 12
*/

///////////////////////////////////////////////////////////////////////////////////////////

//Pointer as a function arguments- Call Reference


//increment functioin 

#include<stdio.h>
void increment(int *p)
{
    *p=*p+1;
}
int main()
{
    int a;
    a=10;
    increment(&a);
    printf("a =%d",a);
}
//output is 11

/////////////////////////////////////////////////////////////////////////////////////////

//Pointers and arrays
/*
memory with array
int A[5]
A[0]=2
A[1]=4    int- 4bytes
A[2]=5    A- 5x4bytes = 20bytes
A[3]=8      
A[4]=1

int A[5]
int *p
p=&A[0]
printf p //200
printf*p //2

printf p+1 //204
printf *(p+1) //4

Elements at index i--         Array cant be incremented like A++  
Address: &A[i] or (A+i)       but Pointers can p++  
Value:   &A[i] or *(A+i)  
*/

#include<stdio.h>
int main()
{
   int A[] = {2,4,58,1};
   int i;
   int *p =A;
   for(int i=0;i<5;i++){
    printf("Address = %d\n",&A[i]);
    printf("Address = %d\n", A+i);
    printf("Value =%d\n",A[i]);
    printf("value =%d\n",*(A+i));

    return 0;
   }
}

////////////////////////////////////////////////////////////////////////////////////////////


