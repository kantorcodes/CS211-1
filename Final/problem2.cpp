/*
2. In the following code, what does function P do?
*/

/*
Function P recursively calculates all possible arrangements of the elements in array v with size n, starting at the index start.
It does this by rotating the array to the left (shifting it one element to the left), and then swapping each element in the array.
*/

#include <iostream>
//Function declarations
void P(int [],int,int);
void Print(int [],int);
void Swap(int [],int,int);
void Rotate_Left(int v[],int,int);
using namespace std;

int main(){
    int N;
    cout<<"Please enter 'N'"<<endl;
    cout<<">>";
    cin>>N;

    int v[100];

    for (int i=0; i<N; i++){
        v[i]=i+1; //initialise
    }

    for(int i=0; i<N; i++){
        cout << v[i] << ", ";
    }

    P(v,0,N);
    cin.get();
    cin.get();

    return 0;
}

/*==================================
 Function P
 ==================================*/
void P(int v[],int start, int n){
    Print(v,n); //print v (n is the size of v)
    if (start<n){
        int i,j;
        for(i=n-2; i>=start; i--){ //for every index i from n-2 to start, decreasing
            for(j=i+1; j<n; j++){ //for every element from i+1 to n, increasing
                Swap(v,i,j); //swap them
                P(v,i+1,n);
            }
            Rotate_Left(v,i,n);
        }
    }
}

/*==============================
 Function Print
 =============================*/
void Print(int v[],int size){
    if (v!=0){
        for (int i=0; i<size; i++){
            cout<<v[i];
        }
        cout<<""<<endl;
    }
}

/*==============================
 Function swap
 ==============================*/
void Swap(int v[],int i,int j){
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

/*===========================
 Function rotate left
 ===========================*/
void Rotate_Left(int v[],int go,int n){
    int tmp = v[go];
    for (int i=go; i<n-1; i++){
    v[i] = v[i+1];
    }
    v[n-1] = tmp;
}
