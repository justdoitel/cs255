/*
THIS CODE WAS MY OWN WORK; IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/

#include <stdio.h>
#include <stdlib.h>
#define minsize 1

int size = 0;
int created =0; 
int cap =minsize;
int *ptr;

//this method pushes a number into our stack
void push(int item){
    if(created==0){ //if the stack is not created this would create a stack and allocate 1 int memory to it
        ptr = calloc(cap, sizeof(int));
        created=1;
    }
    if (size==cap){ //if the stack reaches its limit, the memory would be reallocate double the size
         ptr = realloc(ptr,cap*2*sizeof(int));
         cap=cap*2;
    }
    *(ptr+size)=item; //this would push the number at the top of the stack
    size++; //this would increase the size of the stack
}

int pop(){
    if(size==0){
        printf("cannot pop from empty\n");
         return -1;
    }
    int returnval = *(ptr+size-1); //this is the value we are returning
    size--;
    if(cap!=minsize&size<=cap/4){ //if only 1/4 (or less) of the stack is being used, we resize it down
        ptr=realloc(ptr,sizeof(int)*cap/2); 
        cap = cap/2;
    }
    return returnval;
}

void free_stack(){ //when we free the stack, we reset everything and free the memory allocated for it
    free(ptr);
    size = 0;
    created = 0;
    cap=minsize;
}


int main(int argc, char const *argv[])
{
    for(int i=100;i>=0;i=i-2)
        push(i);
    for (int i=0;i<=100;i=i+2)
        pop();
    

    printf("\n");
    printf("%d,THEEND\n",pop());
    free_stack();
    for(int i=100;i>=0;i=i-2)
        push(i);
    for (int i=0;i<=100;i=i+2)
        pop();
    
    push(1);
    push(2);
    //push(3);
    free_stack();
    
    
}

