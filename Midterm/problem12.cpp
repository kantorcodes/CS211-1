/*
Write a function
int * return_matches(int a[], int & size,TEST t)
which returns an array (allocated off of the heap in the function) containing only the elements
of array a that pass the “test” t. The function iterates through all the elements of a, and
constructs a new array containing all the elements that pass the test.
When the parameter corresponding to “size” is passed in (by reference), it contains the size of
the array a. In the function that variable is modified, so that when “return_matches” returns,
the parameter will contain the number of matches found. This will allow us to print the array
returned by the function, since we know how big it is.
What is a “test”? It’s a Boolean function that tests if an integer meets a specific criteria.
For example
    bool is_even(int n){
        return n%2==0;
    }
To make this work we could use a typedef like:
typedef bool TEST(int)
so now TEST becomes a type and the function “is_even” is indeed of type TEST since it is a function of a
single integer variable and returns a bool.
*/

#include <iostream>
using namespace std;

typedef bool test(int);

bool is_even(int n){
    return n%2==0;
};

int* return_matches(int a[], int size, test t){
    int n=0, length=0;
    for(int i=0; i<size; i++)
        if(is_even(a[i])) length++;

    int* arr=new int[length];

    for(int i=0; i<size; i++){
        if(is_even(a[i])){
            arr[n]=a[i];
            n++;
        }
    }
    return arr;
};

int main(){
    int example[5]={3, 1, 4, 2, 5};
    int* arr=return_matches(example, 5, is_even);
    for(int i=0; i<2; i++) cout << arr[i] << endl;
    delete[]arr;
    return 0;
}
