/*
THIS CODE WAS MY OWN WORK; IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW
*/

#include <stdio.h>
#include <stdlib.h>

/*
this method takes in A, the array to be sorted.
it takes in two ints, p and r, the beginning and ending index of the subarray we are sorting.
it then puts the last index in the correct place by putting every number above it to its right and below it or equal to it to the left.
*/

int partition (int* A, int p, int r){
    int x = *(A+r);
    int i = p-1;
    for (int j=p; j<=r-1;j++){ //this loops through the subarray we are sorting
        if(*(A+j)<=x){ //if the jth index is below the last index, this transfers it to the left. 
            i++;
            int temp=*(A+i);
            *(A+i) = *(A+j);
            *(A+j) = temp;
        }
    }
    int temp=*(A+i+1); 
    *(A+i+1) = *(A+r);
    *(A+r) = temp; //the last three steps put the last index (the pivot) in its correct place.
    return i+1; //this returns the pivot (now in its correct place)

}

/*
this method takes in A, the array to be sorted.
it takes in two ints, p and r, the beginning and ending index of the subarray we are sorting.
it then takes a random index from in between and switch it with the last index of the subarray and then call partiiton and return its result
*/
int rpartition(int* A, int p, int r){
    int i = (rand() % (r - p + 1)) + p; //picks a random number between p and r
    int temp = *(A+i); 
    *(A+i) = *(A+r);
    *(A+r) = temp;
    return partition(A, p, r); //this returns the index that is sorted
}

/*
this method takes in A, the array to be sorted.
it takes in two ints, p and r, and sorts the numbers between those indicies.   
*/
void quicksort(int *A, int p, int r){
    if (p<r){ // if p is not less than r, that means the subarray asked to be sorted is just size one (meaning it's already sorted)
        int q = rpartition(A,p,r); //this calls the rpartition on the array and assigns the index in the correct posiiton to q
        quicksort(A,p,q-1); //sorts the array to the left of q (since the number at q is in its place)
        quicksort(A,q+1,r); //sorts the array to the right of q (since the number at q is in its place)
    }
}

/*
this method takes in arr, the array to be sorted, and len, its length.  
it then calls the recursive quicksort method on the entire array.
*/
void sort (int *arr, int len){
    quicksort(arr, 0, len - 1);
}

int main(int argc, char const *argv[])
{
    int x[100] = {89,66,40,9,80,32,25,18,87,41,44,47,7,35,74,77,82,86,29,23,71,27,85,81,36,45,36,89,13,31,65,51,100,16,90,86,25,70,24,82,96,73,16,57,8,6,45,10,77,80,18,77,15,24,21,11,51,85,31,78,64,34,22,92,60,28,58,78,28,3,44,69,1,84,96,51,21,84,71,5,38,67,79,6,15,85,83,86,16,6,89,51,21,56,34,31,96,39,74,68};
    sort(x,100);
    for(int i=0;i<100;i++){
        printf("%d,",x[i]);
    }
    
}


