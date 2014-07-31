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

int minimum(int arr[]){
    int min = INT_MAX;
    for(int iter=0; iter<rows; iter++){
        if(costs[iter][cols-1]<min) min = costs[iter][cols-1];
    }

    return min;
}

int minimum(int i, int j){
    if(i<j) return i;
    return j;
}

int minimum(int i, int j, int k){
    return minimum(i, minimum(j, k));
}

int cost(){
    //populate array with costs from left adjacent 3 squares
    for(int col=0; col<cols; col++){
        for(int row=0; row<rows; row++){

            //if we're in the first column, then just set to the weight; there's nothing to the left
            if(col==0) costs[row][0] = weight[row][0];
            else{

                //the same thing as minimum(left, up, down)
                costs[row][col] = weight[row][col] + minimum(costs[(row-1+rows)%rows][col-1],
                    costs[row][col-1],
                    costs[(row+1)%rows][col-1]);
            }
        }
    }

    //find least path
    return minimum(costs[cols-1]);
}

int main(){
    cout << "The shortest path is of length " << cost() << endl;
    return 0;
}
