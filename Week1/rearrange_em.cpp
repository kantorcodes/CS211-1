/*
Let k be an array of n distinct integers
void p(int k[], int n)
that will do the following:

1. Find the “middle” element (the element at position n/2) of array k. Call its value m.

2. Rearrange the elements of array k so that all of the elements of k that are smaller than m will
be moved to the positions before m, and all elements of k which are greater than m will occupy
the positions to the right of m.

Test the function:
Write a main program to test the function p for arrays of sizes 5,10,15,20. Fill the arrays with
random values using the rand() function.
For each trial, print out the array both before rearranging by calling function p, and after.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
        cout << arr[i];
        if(i<length-1) cout << ", ";
    }
    cout << endl;
}

void p(int k[], int n){
    int indexOfM = n/2;
    for(int i=0; i<n; i++){
        if((k[i]>k[indexOfM] && i<indexOfM) || (k[i]<k[indexOfM] && i>indexOfM)){
            int temp = k[i];
            k[i] = k[indexOfM];
            k[indexOfM] = temp;
            indexOfM = i;
        }
    }
}

int main(){
    int a[5], b[10], c[15], d[20];
    for(int i=0; i<20; i++){
        if(i<5) a[i] = rand();
        if(i<10) b[i] = rand();
        if(i<15) c[i] = rand();
        d[i] = rand();
    }

    cout << "Before: ";
    printArray(a, 5);
    cout << "After: ";
    p(a, 5);
    printArray(a, 5);

    cout << "Before: ";
    printArray(b, 10);
    cout << "After: ";
    p(b, 10);
    printArray(b, 10);

    cout << "Before: ";
    printArray(c, 15);
    cout << "After: ";
    p(c, 15);
    printArray(c, 15);

    cout << "Before: ";
    printArray(d, 20);
    cout << "After: ";
    p(d, 20);
    printArray(d, 20);

    return 0;
}
