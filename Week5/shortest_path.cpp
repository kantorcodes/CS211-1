/*
1. Modify the code in the handout to include memoization. Modify it additionally so that it
prints the actual shortest path as well as its cost. The path should be output as the sequence of
rows to choose, going from left to right on the original cost array.

2. Many dynamic programming problems may be solved quite simply from the “bottom up.”
Write a program to solve the shortest path problem using a bottom up approach. The path should
be output as the sequence of rows to choose, going from left to right on the original cost array.
*/

#include <iostream>
#include <climits>
using namespace std;

const int rows = 5;
const int cols = 6;
int weight[rows][cols]={
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}}; //313324 = 16

int minimum(int i, int j){
    if(i<j) return i;
    return j;
}

int minimum(int i, int j, int k){
    return minimum(i, minimum(j, k));
}

/*
int fib(int n){
	static int memo[100] = {0, 1, 1};
	if(n==1||n==2) return 1;
	if(memo[n]!=0) return memo[n];
	return memo[n]=fib(n-1)+fib(n-2);
}
*/

int cost(int i, int j){ // i is the row, j is the column
    static int memo[100]={0};

    //base case
    if(j==0) return weight[i][0];

    // recursive call
    int left = cost(i, j-1);
    int up = cost((i-1+rows)%rows, j-1); //negative modulos are calculated strangely in C++, so we need to add rows; otherwise it will return -1 when it should return 4
    int down = cost((i+1)%rows, j-1);

    // find the value of the shortest path through cell (i,j)
    return weight[i][j] + minimum(left, up, down);
}

/*
row  (i-1)   (i-1)%rows    (i-1+rows)%rows
0      -1        -1                4
1       0         0                0
2       1         1                1
3       2         2                2
4       3         3                3
*/

int main(){
    int ex[rows];

    // get the shortest path out of each cell on the right
    for(int i=0; i<rows; i++)
        ex[i] = cost(i, cols-1);

    // now find the smallest of them
    int min = INT_MAX;
    for(int i=0; i<rows; i++){
        if(ex[i]<min) min = ex[i];
    }

    cout << "The shortest path is of length " << min << endl;
    return 0;
}
