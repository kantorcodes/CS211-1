#include<iostream>
#include<climits>
using namespace std;

int at_row, at_col, value;

int maxInArray(int a[], int size){
    int max = INT_MAX;
    for(int i=0; i<size; i++){
        if(a[i]>max) max = a[i];
    }
    return max;
}

int minInArray(int a[], int size){
    int min = 0;
    for(int i=0; i<size; i++){
        if(a[i]<min) min = a[i];
    }
    return min;
}

bool saddle_point_found(int a[][3], int size){
    int max = a[0][0], max_row, min_col;

    //find the max, min in the entire array
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(a[i][j]>max){
                max = a[i][j];
                max_row = i;
                min_col = j;
            }
        }
    }

    int col[size];
    for(int i=0; i<size; i++)
        col[i] = a[i][max_col];

    if(maxInArray(a[max_row], size)!=minInArray(col, size)) return false;
    value = a[max_row][max_col];
    return true;

}

int main(){
    int a[3][3] = {{1, 10, 2}, {2, 5, 3}, {4, 11, 0}};
    int size = 3;
    if(saddle_point_found(a, size))
        cout<< "saddle point found with value "<< value<<" at row "<<at_row<<"and at column "<<at_col<<endl;
    else cout<<" alas no saddle point found :-( " <<endl;
    return 0;
}
