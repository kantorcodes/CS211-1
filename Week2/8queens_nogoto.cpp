//Redo the 8 queens 1 dimensional array program with backtracking REMOVING ALL "GOTOs"

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int count=1;

void printSimple(int board[]){
    for(int i=0; i<8; i++) cout<<board[i]<<" ";
}

void print(int board[]){
	for(int row=0; row<8; row++){
		for(int column=0; column<8; column++){
			if(board[column]==row) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

void check(int column){
    if(column<0) exit(0);
}

bool isValid(int q[], int c){
    for(int i=0; i<c; i++){
        if((q[i]==q[c])||(abs(q[c]-q[i])==(c-i))) return false;
    }
    return true;
}

//Why does this work but the 2 parameter function doesn't?
bool isValid(int board[], int column, int row){
    for(int i=0; i<column; i++){
        if((board[i]==row)||(abs(row-board[i])==(column-i))) return false;
    }
	return true; //No conflict
}

void placeQueen(int board[], int column){
    bool n=false;
    if(column==7){
        cout << "SOLUTION " << count << endl;
        //printSimple(board);
        count++;
        cout << endl;
    }
    else{
        for(int row=0; row<8; row++){
            if(isValid(board, column, row)){
                board[column]=row;
                placeQueen(board, column+1);
            }
            else if(row==7){
                column--;
                row=board[column;
                break; //
            }
        }
        /*
        for(int row=0; row<8; row++){
            if(isValid(board, column, row)){
                board[column]=row;
                placeQueen(board, column+1);
                //cout << row << ", ";
            }
            else if(row==7){
                    column--;
                    row = board[column]+1;
            }
        }
        */
    }
}

int main(){
    int board[8]={0};
    int column=0;
    placeQueen(board, column);
    return 0;
}

/*
void backtrack(){
    column--;
    if(column<0) exit(1);
    row++;
}

int main(){
    int solution=1;
    bool queenWasPlaced=false;
    board[0] = 0;

    for(column; column<8; column++){
        for(row; row<8; row++){
            if(isValid()){
                board[column]=row;
                queenWasPlaced = true;
                break; //Exit this for loop; move to the next column
            }
            if(!queenWasPlaced&&row==7) backtrack();
            else queenWasPlaced = false;
        }
    }

    printSimple();
    backtrack();
}
*/

/*
//Redo the 8 queens 1 dimensional array program with backtracking REMOVING ALL "GOTOs"

#include <iostream>
#include <stdlib.h>
using namespace std;

int row=0, column=0;
int board[8][8]={0};

bool isValid(){
    for(int i=0; i<8; i++){
        if(board[row][i]==1) return false; //Row test
    }
    for(int j=1; ((column-j)>=0)&&((row-j)>=0); j++){
		if(board[row-j][column-j]==1) return false; //Up-diagonal test
	}
    for(int k=1; ((column-k)>=0)&&((row+k)<8); k++){
		if(board[row+k][column-k]==1) return false; //Down-diagonal test
	}
	return true; //No conflict
}

void backtrack(){
    column--;
    if(column<0)
}

int main(){
    int solution=1;
    bool queenWasPlaced=false;
    board[0][0] = 1;

    for(column; column<8; column++){
        for(row; row<8; row++){
            if(isValid()){
                board[row][column]=1;
                queenWasPlaced = true;
                break; //Exit this for loop; move to the next column
            }
            if(!queenWasPlaced) backtrack();
        }
    }
}
*/
