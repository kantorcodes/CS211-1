s/*
Write a program that inputs two integers n and k, where n>=k. Your program should calculate
the number of different ways that k bishops could be placed on an nXn chessboard.

Structure your program using the backtracking scheme that we have used for the eight queens
problem. What needs to be modified is the “OK” function.
*/

#include <cstdlib>
#include <iostream>
using namespace std;

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
};

void backtrack(int &col){
    col--;
    if(col==-1) exit(1);
};

void print(int q[]){
    static int count =0;
    cout<< ++ count<<endl<<endl;
    int i;
    for(i=0; i<8; i++)
    cout<<q[i]<<" ";
    cout<<endl<<endl;
};

int main(){
    int k, n;
    while(true){

        //User input
        cout << "Enter n: ";
        cin >> n;
        cout <
        < "Enter k: ";
        cin >> k;
        if(n<0) break;

        //Solution/backtracking algorithm
        int q[n]; q[0]=0;
        int c=0;
        bool from_backtrack=false;

        while(true){
            while(c<n){
            if(!from_backtrack)
                q[c]=-1;
                while(q[c]<n){
                    q[c]++;
                    if(q[c]==n){
                        backtrack(c);
                        continue;
                    }
                    if(ok(q,c)) break;
                }
                c++;
                from_backtrack=false;
            }
            print(q);
            backtrack(c);
            from_backtrack=true;
        }
    }
    return 0;
}
