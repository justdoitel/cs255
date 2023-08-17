/*
THIS CODE WAS MY OWN WORK , IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/
#include <stdio.h>
#include <stdlib.h>

//this fuction takes a double and rounds it to the nearest int.
int round(double num){
    if(num>0) return (int)(num + 0.5); //if the number is positive, we can add 0.5 and just truncate the decimal
    if(num<0) return (int)(num - 0.5); //if the number is negative, we can  subtract 0.5 and just truncate the decimal
    return 0; //if the number is neither pos nor neg, it's 0
}

//this counts takes a string and returns its length (up until the nul)
int len(char *string){
    int count=0;
    while(*string!='\0'){ //this checks that we haven't hit the nul yet
        count++;
        string++; //this goes to the next char
    }
    return count; 
}

// this fuction takes a string and turns it all its uppercase letters into lower 
char *lower(char *string){
    int length = len(string);
    char *ptr = calloc(length+1,sizeof(char)); //we create a ptr to hold a copy of the string (in case of literal being passed)
    for(int i=0; i<length;i++){ //this loop copies the string to our new pointer
        ptr[i] = string[i];
    }
    ptr[length] = '\0'; 

    int index = 0;
    while(ptr[index]!='\0'){ //this while loop goes through the string
        if (ptr[index] >= 'A' && ptr[index] <= 'Z') //this checks if the char is an upper case char
        ptr[index] = ptr[index] + 32; //if it is, it converts it into lower case
        index++;
    }
    return ptr;
}

//this takes in an array with its row and col randomly exchange rows and cols
void scramble(int **arr, int rows, int cols){
    for (int i=0; i<rows;i++){
        int therow = rand() % rows; //picks a random number between 0 and row to exchange with
        int *temp = arr[i]; //stores a pointer to the array at current index
        arr[i] = arr[therow]; //exchange the row
        arr[therow] = temp; //assign the stored temp
    }
}

//this function takes an int and converts it to string
char *convert(int n){
    if(n==0){ //if n is 0, we simply return 0.
        char* c = calloc(2,sizeof(char));
        c[0] = '0'; c[1] = '\0';
        return c;
    } 

    int size = 1;//for the null pointer
    int temp = n;
    int neg=0;
    while(temp!=0){ //at the end of the loop, size==size of n
        temp=temp/10;
        size++;
    }
    if(n<0){ //if n is negative, we'd need one additional charachter
        size++;
        neg=1;
    }

    char *result = calloc(size,sizeof(char));
    result[--size] = '\0'; //the last char would be nul
    
    while(n!=0){ // once n is 0, we know we're done
        size--; //goes one right in the place value
        if(!neg)
            result[size] = (n%10)+48;
        else
            result[size] = -1*(n%10)+48;
        n=n/10; //now that we've copied the last digit, we can get rid of it and proceed.
    }
    if(neg) result[0]= '-'; 
    return result;
}


//this takes a char and convert it into binary using the len provided
void binary(char num, int len){
    int bin = 0; //this is to hold the binary
    int temp = num; //this holds a copy of num to modify it
    int neg=0; //this holds the negative property of the number
    if (num<0){
        neg=1;
        num = -1*num; //if the number is negative, we'd be treating it like positive till way into the end
        temp = num;
    }
    int mult=1;
    while(temp!=0){ //this loop turns the number into binary;
        bin = bin + temp%2*mult;
        temp=temp/2;
        mult=mult*10;
    }
    
    int length = len;
    char *p = malloc((len+1)*sizeof(char)); //this allocates memory to our result
    p[len] = '\0';

    while(len>0){ //this loop fills our result with the binary number.
        len--;
        
        if(bin==0){
            p[len] = 48;
        } else{
            p[len] = (bin%10)+48;
        }
        bin=bin/10;
    }
    if(!neg){ //if our number is not negative, we're done
        printf("%s\n",p);
        free(p);
        return;
    }

    for(int i=0;i<length;i++){ //this flips the 0 to 1 and vice versa
        if(p[i]=='0') p[i]='1';
        else p[i] = '0';
    }
    
    while(p[--length]!='0'){ //this finds the first 0 (from the right) and turns every digit until into 0 
        p[length] = '0';
        if(length==0) break; //if we reach the beginning without finding 0, we break.
    }
    if (length!=0) p[length]='1'; //if we didn't break earlier (that is we found a zero), we turn it into 1
    printf("%s\n",p);
    free(p);
}

