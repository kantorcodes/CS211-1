/*
Write a program that inputs two integers n and k, where n>=k. Your program should calculate
the number of different ways that k bishops could be placed on an nXn chessboard.

Structure your program using the backtracking scheme that we have used for the eight queens
problem. What needs to be modified is the “OK” function.
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int k, n; //number of bishops, size of the board

//q is an array of squares, where b is a bishop and q[b] is the square the bishop occupies
bool ok(int q[], int b, int size){
    //identify the row and column the bishop is in
    int row = q[b]/size, column = q[b]%size, current_row, current_column;

    for(int i=0; i<b; i++){ //for every bishop
        current_row = q[i]/size;
        current_column = q[i]%size;

        //diagonal test
        if(abs(row-current_row)==abs(column-current_column)) return false;
    }

    return true;
};

void backtrack(int &bishop){
    bishop--;
    if(bishop==-1) exit(1);
};

void print(int q[]){
    static int count =0;
    cout << ++count << endl << endl;
    for(int i=0; i<n; i++)
    cout << q[i] << " ";
    cout << endl << endl;
};

/*
For each of the k bishops, (69)
look at all the possible boxes the bishop could be in (71)
If it's ok to put bishop c in box q[c], (72)
    then do so, and go to the next bishop. (82)
        If there is no next bishop, then one or more of the bishops are causing an issue, so backtrack (78)
        But if there is no next bishop and the solution was okay, then break out of the whole loop (q[c]<n*n still satisfied) and do the after-all-bishops sequence. (73)
If it's not ok to put bishop c in box q[c], (74)
    then go to the next box. (75)
If a solution was found, then you don't want to go back a box (like going back a column), so store q[c] and go to the next bishop. (83)
When a solution is found, q[c]++ (akin to incrementing the first row in the 8 queens problem), i.e. the starting point. (91)
*/

int main(){
    while(true){

        //User input
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter k: ";
        cin >> k;
        if(n<0) break;

        //Solution/backtracking algorithm
        int* q = new int[k]; //q[bishop] is a square on the n*n grid
        int b = 0;
        q[b] = -1;

        while(true){ //until we found all the possible solutions
            while(b<k){ //for each bishop
                while(q[b]<n*n){ //for each square
                    q[b]++;
                    if(ok(q,b,n)) break;
                    if(q[b]==n*n){
                        backtrack(b);
                        continue;
                    }
                    else{
                    }
                }
            }
            print(q);
            backtrack(b);
        }
    }
    return 0;
}








