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

int minimum(int arr[]){
    int min = INT_MAX;
    for(int iter=0; iter<rows; iter++){
        if(costs[iter][cols-1]<min) min = costs[iter][cols-1];
    }

    return min;
}

int rminimum(int arr[]){
    int min = INT_MAX;
    for(int iter=0; iter<rows; iter++){
        if(arr[iter]<min) min = arr[iter];
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

//inefficient trace of row sequence
int trace(){
    int sequence[cols] = {0}, buffer[rows] = {0};
    for(int col=0; col<cols; col++){
        for(int row=0; row<rows; row++){
            buffer[row] =  costs[row][col];
        }
        sequence[col] = rminimum(buffer);
        cout << sequence[col] << ", ";
    }
}

int cost(){
    //populate array with costs from left adjacent 3 squares
    for(int col=0; col<cols; col++){
        for(int row=0; row<rows; row++){
            if(col==0) costs[row][0] = weight[row][0];
            else{
                costs[row][col] = weight[row][col] + minimum(costs[(row-1+rows)%rows][col-1],
                    costs[row][col-1],
                    costs[(row+1)%rows][col-1]);
            }
        }
    }

    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            if(costs[row][col]/10>1) cout << costs[row][col] << " ";
            else cout << costs[row][col] << "  ";
        }
        cout << endl;
    }

    //find least path
    return minimum(costs[cols-1]);
}

int main(){
    cout << "The shortest path is of length " << cost() << endl;
    trace();
    return 0;
}
