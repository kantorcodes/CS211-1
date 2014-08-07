#include<iostream>
#include<climits>
using namespace std;

int at_row, at_col, value;

bool saddle_point_found(int a[][5], int size){
    int max_row = 0, min_col = INT_MAX;
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if(a[r][c]<min_col)
                min_col = c;
        }
        if(a[r][c]>max_row) max_row = r;
    }
    at_row = max_row;
    at_col = min_col;
    value = a[at_row][at_col];
    if()
}

int main(){
    if(saddle_point_found(a, size, at_row, at_col, value))
        cout<< "saddle point found with value "<< value<<" at row "<<at_row<<"and at column "<<at_col<<endl;
    else cout<<" alas …no saddle point found :-( " <<endl;
    return 0;
}
