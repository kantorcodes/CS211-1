/*
CS211

The n queens problem


By the n queens problem we mean the problem of placing n queens on an nXn chessboard
in such a way that no queen can capture any other on the next move. In class we solved the 8
queens problem.

Write a function that inputs an integer n and returns the number of solutions to the n
queens problem. Your function should use the one dimensional representation for the board,
the algorithm we discussed in class, and no gotos.

Test your function with a main program that prompts the user for an integer n. The main
program then calls the function n times, once for each number from 1  n, and then prints the
number of solutions to each of these problems, one on a line.

For example, if you enter n=5 your program should output:

1. There are _____ solutions to the 1 queens problem.
2. There are _____ solutions to the 2 queens problem.
3. There are _____ solutions to the 3 queens problem.
4. There are _____ solutions to the 4 queens problem.
5. There are _____ solutions to the 5 queens problem.

Now, since each time through the loop you will need an array q of a different length, you will
need to allocate the array off of the heap (which we mentioned in class) and not the run-time
stack. To do this you use the new operator to request the heap to dynamically allocate the
memory for you.

For example, to get a one dimensional array of integers of size n and called q, we use the
following syntax:

int* q = new int[n];


This allocates the array for us dynamically, at run-time. After this we can use the array q just
as if it had been declared normally and it has n elements denoted q[0] through q[n-1].

When we no longer need the memory that was allocated to the array, we write:

delete [ ] q;


For this problem, you pass the required length for the array q to your function, which then
allocates q dynamically (using new) and uses it to hold the solutions for the given size. Each
time the function exits, you must deallocate q by calling delete [ ] q.

For this problem, test your program for n=8.

For some more details on how to use new and delete, go to the
video section of the course web site and see the video called
Dynamically allocated arrays.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
};

bool backtrack(int &col){
    col--;
    if(col==-1) return false;
    return true;
};

/*
void print(int q[]){v
    static int count =0;
    cout<< ++ count<<endl<<endl;
    int i;
    for(i=0; i<8; i++)
    cout<<q[i]<<" ";
    cout<<endl<<endl;
};
*/

int solve(int n){
    int *q=new int[n];
    //int q=[n];
    for(int i=0; i<n; i++) q[i]=0;
    int c=0, solutions=0;
    bool from_backtrack=false;

    while(true){
        while(c<n){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<n){
                q[c]++;
                if(q[c]==n){
                    if(backtrack(c)) continue;
                    else return solutions;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        solutions++;
        if(!backtrack(c)) return solutions;
        from_backtrack=true;
    }
    delete[]q;
    return solutions;
};

int main(){
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << "There are " << solve(i) << " solutions to the " << i << " queens problem." << endl;
    }
    return 0;
}

