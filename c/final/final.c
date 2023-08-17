/*
THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/

#include <stdio.h>
#include <stdlib.h>

//this counts takes a string and returns its length (up until the nul)
int len(char *string){
    int count=0;
    while(*string!='\0'){ //this checks that we haven't hit the nul yet
        count++;
        string++; //this goes to the next char
    }
    return count; 
}

//concatenates two strings -- s1 and s2 == and returns their concatenation
char* cat(char* s1, char* s2){
    int x=len(s1);
    int y=len(s2);
    char *ptr = calloc(x+y+1,sizeof(char)); //creates the return string (which would have length of the sum of the two lengths and one more for nul)
    for (int i=0;i<x;i++){ //this loops copies s1
        ptr[i]=s1[i];
    }
    for (int i=x;i<x+y;i++){ //this loop copies s2 until the end
        ptr[i]=s2[i-x]; //i-x done so that we start copying at s2[0]
    }
    ptr[x+y]='\0'; //the string ends with nul
    return ptr; //return the string
} 

//converts a number to a charachter of binary digits and returns the string of the binary digits.
char *convert(int num){
    char *ptr = calloc(33,sizeof(char)); //33 charachters allocated so that the 33th (32nd index) would hold the nul at the end
    int i=31; //the 31st index (the 32nd charachter) is where we begin looping since it's the first place form the right
    int x=1; //this would track what we compare num with
    while(i>=0){ //loops until every index of our ptr is filled approprietly
        if(num&x){ //this would be 0 unless that ith bit is 1 since x has all zeros except at the ith bit
            ptr[i]='1';
        }
        else{
            ptr[i]='0';
        }
        i--;
        x=x<<1; //multiply x by 2 (by shiftin)
    }
    ptr[32]='\0'; //as usual, the last char becomes nul
    return ptr;
}

//setting the struct up
struct u { 
    int *set;
    int len;
};


//takes two two sorted sets as int arrays with their size and returns how many distinct numbers there would be if the sets were combined.
int sizeofmerge(int* arr1,int size1, int* arr2, int size2){
    int i = 0, j = 0, size=0; //i traverses the first array and j the second while size keeps track of the size of the distinct numbers
    while (i<size1 && j <size2) { //goes through each array simultaneously until the end of one (or both) is reached (only counting distinct values)
        if (arr1[i] < arr2[j]){
            size++; i++;
        }
        else if (arr1[i] > arr2[j]){
            size++; j++;
        }
        else{
            size++; i++; j++;
        }
    }
    while (i < size1){ //in case that there's more of size 1 (but we just reached the end of size 2)
        size++; i++;
    }
    while (j < size2){ //in case that there's more of size 2 (but we just reached the end of size 1)
        size++; j++;
    }
    return size;
}

//takes two structs and finds their union (as a set)
struct u* set_union(struct u *set1, struct u *set2){
    struct u *toreturn = malloc(sizeof(struct u)); //allocate the memory to be returned
    toreturn->len=sizeofmerge(set1->set,set1->len,set2->set,set2->len); //get the length of the set using pre-defined method
    toreturn->set=calloc(toreturn->len,sizeof(int)); //now create the array for the union set

    int i = 0, j = 0, k = 0;
    while (i<set1->len && j<set2->len) //goes through each array until one (or both) have gotten to an end
    { 
        if (set1->set[i] < set2->set[j]) //if the number we're at from set 1 is smaller, that'd be the next number on our union array
            toreturn->set[k++] = set1->set[i++];
        else if(set1->set[i] > set2->set[j]) //if the number we're at from set 2 is smaller, that'd be the next number on our union array
            toreturn->set[k++] = set2->set[j++];
        else { //if they're equal, then that number would be the next in our array (but, the pointer for both sets must be incremented)
            toreturn->set[k++] = set1->set[i++];
            j++;
        }
    }
 
    while (i < set1->len) //if the loop was exited because we had finished set 2, we just copy set 1
        toreturn->set[k++] = set1->set[i++];

    while (j < set2->len) //similarily, if the loop was exited because we finished set 1, we just copy set 2
        toreturn->set[k++] = set2->set[j++];

    return toreturn;
}

//This method takes different strings from a user (separated by space) and, upon detected EOF, it'd return the strings in an array
char** lines(void){
    int length=0; //refers to the length of the current word
    int size=0; //refers to the size of the string array
    char curr; //used to store the charachter being inspected at the time
    char**toreturn; //used to return the string array
    while((curr=getchar())!=EOF){ //per the instruction, we weren't allowed to use scanf or other function (except for getchar())
        if(size==0) toreturn = calloc(1,sizeof(char*)); //this allocates memory for the pointer to the first string
        else toreturn = realloc(toreturn,(size+1)*sizeof(char*)); //this expands extra memory for the pointer to the next string
        size++; //size is increased to reflect that we are on a new line (or our first line)
        toreturn[size-1] = calloc(1,sizeof(char)); //one empty memory allocated to store the current string
        while(curr!='\n'){ //this goes through the charachter and appends them to the current string
           toreturn[size-1]=realloc(toreturn[size-1],sizeof(char)*(length+1));//each letter we encounter, the memory size allocated for the string increments
           toreturn[size-1][length] = curr; //the current charachter is appended at the end
           length++; //length is incremented to reflect how a letter is added at the end
           curr=getchar(); //prepared for the next iteration
        }
        toreturn[size-1]=realloc(toreturn[size-1],sizeof(char)*(length+1)); //at the end, the string is expanded by one more (to store nul)
        toreturn[size-1][length] = '\0';
        length=0; //now, we reset the length to prepare for the next iteration
    }
    return toreturn;
}