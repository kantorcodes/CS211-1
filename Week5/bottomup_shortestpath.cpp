#include <climits>
#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;
int weight[rows][cols]={
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}}; //313324 = 16

//setup blank 2D array
int costs[rows][cols] ={0};
int directions[rows][cols] = {0}; //-1=up; 0=left; 1=down
int min_index; //to be used in main when determining where to start the path trace

int minimum(int arr[]){
    int min = INT_MAX;
    for(int iter=0; iter<rows; iter++){
        if(costs[iter][cols-1]<min) min = costs[iter][cols-1];
    }

    return min;
}

int cost(){
    //populate array with costs from left adjacent 3 squares
    for(int col=0; col<cols; col++){
        for(int row=0; row<rows; row++){

            //if we're in the first column, then just set to the weight; there's nothing to the left
            if(col==0) costs[row][0] = weight[row][0];
            else{

                //determine costs for adjacent cells, moving left to right
                int up = costs[(row-1+rows)%rows][col-1];
                int left = costs[row][col-1];
                int down = costs[(row+1)%rows][col-1];

                //calculate min(left, up, down) and determine direction in the cell, i.e. which way the shortest path is going
                int min = left;
                directions[row][col] = 0;
                if(up < min){
                    min = up;
                    directions[row][col] = -1;
                }
                if(down < min){
                    min = down;
                    directions[row][col] = 1;
                }

                //add weight in current cell to min(up, left, down); insert into costs array
                costs[rows][col] = weight[row][col] + min;
            }
        }
    }

    //find least path
    int min = INT_MAX;
    for(int iter=0; iter<rows; iter++){
        if(costs[iter][cols-1]<min){
            min = costs[iter][cols-1];
            min_index = iter;
        }
    }

    return min;
}

int main(){
    //array containing the sequence of rows which the path takes
    int seq[cols];

    //print shortest path length
    cout << "The shortest path is of length " << cost() << endl;

    //trace rows
    seq[cols-1] = min_index;
    for(int col=cols-2; col>=0; col--) seq[col] = seq[col+1] + directions[seq[col+1]][col+1];

    //add 1 to rows because of zero-based indexing
    for(int col=0; col<cols; col++) seq[col]++;

    //print path
    for(int j=0; j<cols; j++) cout << seq[j] << " ";

    return 0;
}
