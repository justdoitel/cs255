/*
THIS CODE WAS MY OWN WORK; IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/

#include <stdio.h>
#include <stdlib.h>
#define null 0

struct Node{ //This is the framework for our type "node" with two variables (int and reference to another node (next)) 
    int num;
    struct Node* next;
};

typedef struct Node Node;

int size=0; 
Node *head;
int created=0;

//this method creates a node with the value of the int passed and makes it the head of our linkedlist. 
void push(int item){
    if(created==0){ //this creates our linked list for the first time with the int provided as the head
        head=malloc(sizeof(Node));
        head->num = item;
        head -> next = null;
        created = 1; 
    }
    else{ //if the linked list has already been created, then we create a node with the passed int and make it point to the old head and make it the new head
        Node *temp = malloc(sizeof(Node));
        temp->num = item;
        temp -> next = head;
        head = temp;
    }
    size++; 
}

//this method frees the head and returns its value and update the head of our list to whatever follows the head
int pop(){
    if(size==0){
        printf("cannot pop from empty\n");
        return -1;
    }
    int toreturn = head->num;
    Node *temp = head;
    head=head->next;
    free(temp);
    size--;
    return toreturn;
}

//this resets everything back to how it was before the first push was done (that is, before our linked list was created)
void free_stack(){
    while(size!=0){ //this is done to free all the memory allocated (as opposed to just the head)
        pop();
    }
    created=0;
} 



int main(int argc, char const *argv[])
{
    for (int i=100;i>=0;i--){
        push(i);
    }
    for (int i=100;i>0;i--){
        printf("%d",pop());
    }
    free_stack();
}
