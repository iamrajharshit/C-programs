
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



//ARRAYS AS FUNCTON ARGUMENTS
//sum of element code
#include<stdio.h>
int SumOfElements(int a[])
 {
    int i, sum=0;
    for(i=0; i<size ;i++)
 }
int main{
    int a[]={i,2,3,4,5};
   
    int size =sizeof(a)/sizeof(a[0]); //here its giving total elements of the array
    int total = SumOfElements(a);
    
    return 0;
}

//calculating the size inside the function
#include<stdio.h>
int SumOfElements(int a[]) //update insted of cal the size in function we should pass the size of the array as para.
 {                         // making int SumOfElements(int a[], int size)
    int i, sum=0;
    printf("SOE - Size of a=%d, Size of a[0]=%d\n",sizeof(a),sizeof(a[0]));
    int size =sizeof(a)/sizeof(a[0]);
    for(i=0; i<size ;i++)
 }
int main{
    int a[]={1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);   
    int total = SumOfElements(a);
    printf("Sum of elements =%d\n",total);
    printf("main - size of a =%d, size of a[0] =%d\n",sizeof(a),sizeof(a[0]));
    return 0;
}

/*
output1
SOE - size of a = 4, size of a[0] = 4
Sum of elements = 1
Main - size of a = 20 size of a[0] = 4


output2

SOE - size of a = 4, size of a[0]= 4
sum of elements = 15
Main - size of a = 20, size of a[0]= 4
*/


/* 
A variable name which is used as an array is different from a variable which is pointed to integer.
we cab=n use name of the array to get the pointer to the first element.
when its an array &a[0] or just a is the address of first element.
a[i] is interprated as *(A+i)
array is passed by reference so we can modify the elements of the array in the call function.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//CHAR ARRAYS AND POINTERS

/*
1) HOw to store strings
size of array>= no. of char in the srting +1 (+1 for null value '\0')

"John" size>=5
char c[8];
c[0]='j';c[1]='h';c[2]='o';c[3]='n';c[4]'\0';
string in c need to be terminated with NULL char
*/

//code

#include<stdio.h>
int main()
{
  char c[20];
  c[0] = 'j';
  c[1]='h';c[2]='o';c[3]='n';c[4]'\0';
  int len = strlen(c);
  printf("Length =%d\n",len);

  char d[]="Drick";
  printf("Size in bytes =%d\n",sizeof(c));
  int len =strlem(c);
  printf("Length = %d\n",len);
}

/*
2) Arrays and pointers arew different types that are used in similar manner

char c1[6] = "Hello";
char* c2;
c2 =c1; #using the name of the array returns the address of the array

print(c2[1]);
c2[0]='A'; // "Aello"
c2[i] is *(c2+i) //derefrencing and finding the value

*/

/*
3) Arrays are always passed to function by refrence, we olny pass the base address of
   the array in a pointer variable and we donot pass a whole copy of the array.
   the compiler does not let us to do that.

*/

#include <stdio.h>
void print(char* c)
{   // this print fuction does not have any idea that this array is of size 20, it only knows the base address.
    int i=0;
    while(c[i]!='\0'){  //*(c+i) and c[i] is same //to read the array not to write(cant make changes) anything "we use const before the para"
        printf("%c",c[i]);
        i++;
    }
}
int main()
{
  char c[20]= "Hello"; //null terminal is implicit
  //char *c ="Hello"; this acts as an constant and it cant be modified!
  print(c);
}
//OUTPUT : Hello

// Concept of string constants and constant pointers
/*
taking in the above program

first main function is invoked
whenver a fun is called some amount of memory from the stack is allocated for the execution of that function.
Its called the STACK FRAME of that function.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//POINTER WITH 2D 3D arrays

/*
 1D array: int A[5]={2,4,6,8,10}
           int *p=A; pointer p returns A first element
           print p//200 (cinsidering the A location)  
           print *p//2
           print *(p+2)//6 
           //even *(A+i) is same as A[i] and (A+i) is same as &A[i]
           //even *A can be used for derefrencing 


2D array: int B[2][3] //we are creating 2 1D araay of 3 elements each!
                      //3*4= 12 bytes
            if we see B[0] as 400 B[1] will be 412
            here B[0]has sub blocks B[0][0], B[0][1], B[0][2] therefore 12bytes

            // int *p=B; (compilation error)
            here B will return a pointer to 1D array of 3 integers not just a integer           
            the type of the pointer matters when we perform pointer arthmatics or when we derefrance

            //int *p[3]=B; (this will work)
            print p //400 (p is returing pointer to an 1D array of 3 int)
            print B or &B[0]//400
            print *B or B[0] or &B[0][0]//400 (*B is returing pointer to an int)
            print &B[0][0]// 400 (here it is just address )
            print B+1 or B[1] or &B[1][1] //412 (400+ size of next 1-D array of 3 integers)
            print *(B+1)+2 or B[1]+2 or &B[1][2]//420
            print *(*B+1)        //B-> int (*)[3]
                                 //B[0] -> (will return) int *
                                 //now adding 1 B[0]+1 will take us to 4 bytes ahead will return 404
                                 // final exp will be &B[0][1] //i.e 3
                                  
            B[i][j] = *(B[i]+[j])
                    = *(*(B+i)+j)                        
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//POINTER AND MULTI-D ARRAYS

/*
  
Using above data 
2-D array
B[i][j]=*(B[i]+[j]) = *(*(B+i)+j)



3D array: int C[3][2][2] // 3D array is colection of 2D array
                         // we are creating 3 (collection 2*2D array of 2 int each) 
                         // 2*2*4 bytes size of each 3D array 

                if we see C[0] as 800 then C[1] will be 816
                here C[0] has sub blocks of 2*2D arrays //C[0][0][0] C[0][0][1]
                                                        //C[0][1][0] C[0][1][1]

                print C // 800
                Print *C or C[0] or &C[0][0] //800  
                Print *(C[0][1]+1) or C[0][1][1]//9

                Print *(C[1]+1) or C[1][1] or &C[1][1][0] //  



                C[i][j][k] = *(c[i][j]+k) = *(*(C[i]+j)+k) = *(*(*(C+i)+j)+k)                                     

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//POINTERS AND DYNAMIC MEMORY

/*
Application's Memory
////////////////////
/                  /
/      HEAP        /
/                  /   
////////////////////
/                  /
/      STACK       /  function calls    }strack frame
/                  /  Local variables   }
////////////////////
/    STATIC        /  
/        GLOBAL    /   Global
////////////////////
/    CODE          /   Instructions
/        TEXT      /
////////////////////
*/

#include<stdio.h>
int total;
int Square(int x){
    return x*x; //x**2
}
int SquareOfSum(int x, int y){
    int z = Square(x+y);
    return z;
}
int main(){
    int a=4,b=8;
    total = SquareOfSum(a,b);
    printf("Output =%d",total);
} //output output =144

//actual allocation of the local variables happens from this stack druing run time
// Stack Overflow
/* 
If our call stack grows beyond the reserved memory for the stack,
like for example, if a method A() calls B(), B() calls C(), and we exhaust the
whole space reserved for the stack is called Stack Overflow. And our program will crash.
bad recursion causes stack overflow. (recursion goes infinitely)
*/

//HEAP memory can be controlled. (Free pool of memory) its a dynamic memory
//HEAP is a DataStr

///////////////////////////////////////////////////////////////

//Dyn. Memory
/*
FOR c (func can be used in c++)
malloc
calloc
realloc
free

FOR c++ (operators)
new 
delete
*/

//malloc

#include<stdio.h>
#include<stdlib.h>
int main(){
//when we use 
int a; //it goes on the stack
//while when we use 
int *p;
p=(int*)malloc(sizeof(int));//malloc helps in getting desired memory in HEAP
/*in heap 4 bytes of the memory is reserved when we say malloc and pass as argument (sizeof(int))
//malloc will return a pointer to the starting address of this block
and malloc return a void pointer* (here we have done type casting as p stores int pointer)
now P points to 200(memory location in HEAP) 
to access the part. block by keeping a pointer variable which will be local to function.
to fill in something in the mem.loc 200 we need to dereference this location using the pointer P and then put in some value.
*/
*p=10;
free(p); //to free the memory
p=(int*)malloc(sizeof(int));
*p=20; //reasigning
p=(int*)malloc(20*sizeof(int)); //20 blocks of 4byte
// p[0],p[1],p[2],p[3]
// *p *(p+1) and so
}





