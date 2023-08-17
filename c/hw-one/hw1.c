/*
THIS CODE WAS MY OWN WORK , IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/

#include <stdio.h>

// a method that prints the fibonnaci sequence up until an int n
void fib(int n) { 
    if (n<0) { 
        printf ("Negative entry not allowed!\n"); 
        return;
    }
    if(n==0){ 
        printf ("0\n"); 
        return;
    }
    unsigned long num1=1; 
    unsigned long num2=1;
        for (int i = 1; i < n; ++i) {
            printf("%lu, ",num1);
            unsigned long lasttwo = num1 + num2;
            num1 = num2;
            num2 = lasttwo;
        }
        printf("%lu\n",num1);
}

//takes a string and reverses it
void reverse(char *s){ 
    int length=0;
    while(s[length]!='\0'){ 
        length++;
    }
    printf("%s\n",s);
    for(int i=length-1;i>=0;i--){
        printf("%c",s[i]);
    }
    printf("\n");
}

//prints out all the factors of the long passed as a parameter
void factors(long num){  
    for(long i=2; i<=num; i++){
        if(i==num){
           printf("%ld\n",i);
           return;  
        }
        if(num%i==0) { 
            printf("%ld,",i);
            num=num/i;
            i--;
        }
    }
}

//used as a helper for arithmetic. it takes numbers a and c and print the result after computing them with the operator passed as a char in b
void arit(int a, char b, int c){ 
    if(b=='+')
    printf("Sum: %d\n",a+c);
    else if(b=='-')
    printf("Difference: %d\n",a-c);
    else if(b=='*')
    printf("Product: %d\n",a*c);
    else if(b=='/'){
        if(c==0) { //if denominator is zero, it'll just quit after an error message
            printf("Error: division by zero\n");
            return;
        }
        if(a>0){ //if nominator is positive, we can divide like normal and return a remainder
        printf("Quotient: %d\n",a/c);
        printf("Remainder: %d\n",a-(a/c*c));
        } else if(a==0){ //if nominator is zero, remainder and quotient would both be one
        printf("Quotient: %d\n",0);
        printf("Remainder: %d\n",0);
        } else{ //this is the case for negative nominators
            if(a-(a/c*c)==0){ //if the remainder is zero, we just return zero for remainder and divide like normal
            printf("Quotient: %d\n",a/c);
            printf("Remainder: %d\n",0);
            } else{ //in the case that the remainder is not zero but the nominator is negative, the following happens
            printf("Quotient: %d\n",a/c-1);
            printf("Remainder: %d\n",(a/c-1)*-1*c+a);
            }
        }

    }
    
}

//this method asks a user for operation and scans for two numbers with an operator charachter in the middle. It quits when EOF is detected. 
void arithmetic(void){ 
    int a;
    char b;
    int c;
    do{
    printf("operation: ");
    if(scanf("%d %c %d", &a, &b, &c)!=3) 
    break;
    arit(a,b,c); //this calls arit (the helper method defined above) using the scan
    } while(getchar()!=EOF); //this ensures that the program would stop at an EOF
}