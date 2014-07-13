/*
Write a program which allocates the integers 1-8 to the squares in the figure above, subject to
the restrictions that no two adjacent squares contain consecutive integers
*/

/*
   _ _
 _|1|2|_
|0|3|4|7|
  |5|6|

*/

#include <cstdlib>
#include <iostream>
using namespace std;

void backtrack(int &square){
    square--;
    if(square==-1) exit(1);
};

bool ok(int q[8], int square){
    int adjacents[8][4]={{-1, -1, -1, -1},
                        {0, -1, -1, -1},
                        {1, -1, -1, -1},
                        {0, 1, 2, -1},
                        {1, 2, 3, -1},
                        {0, 3, 4, -1},
                        {3, 4, 5, -1},
                        {2, 4, 6, -1}};
    for(int i=0; i<square; i++){
        if(q[i]==q[square]) return false;
    }
    for(int j=0; adjacents[square][j]!=-1; j++){
        if(abs(q[square]-q[adjacents[square][j]])==1) return false;
    }
    return true;
};

void print(int q[8]){
    static int count=0;
    cout << endl;
    cout << "  " << q[1] << " " << q[2] << endl;
    cout << q[0] << " " << q[3] << " " << q[4] << q[7] << endl;
    cout << "  " << q[5] << " " << q[6] << endl;
}

int main(){
    int q[8]={0}, square=0;
    q[square]=1;
    bool from_backtrack=false;

    while(true){
        while(square<8){
        if(!from_backtrack)
            q[square]=-1;
            while(q[square]<8){
                q[square]++;
                if(q[square]==8){
                    backtrack(square);
                    continue;
                }
                if(ok(q,square)) break;
            }
            square++;
            from_backtrack=false;
        }
        print(q);
        backtrack(square);
        from_backtrack=true;
    }
    return 0;
}

/*
void backtrack(int &square){
    square--;
    if(square==-1) exit(1);
}

bool wasUsed(int cross[8], int value){
    //Value previously used
    for(int i=0; i<8; i++){
        if(cross[i]==value) return true;
    }
    return false;
}

bool ok(int cross[8], int adjacents[8][4], int square, int value){
    //Value conflicts with adjacent square
    for(int i=0; adjacents[square][i]!=-1; i++){
        if(abs(value-cross[adjacents[square][i]])==1) return false;
    }

    //Value is fine
    return true;
}

int main(){

    /*
	int cross[8]={0}, value=1, square=0;
    bool used=false;
	int adjacents[8][4]={{-1, -1, -1, -1},
                        {0, -1, -1, -1},
                        {1, -1, -1, -1},
                        {0, 1, 2, -1},
                        {1, 2, 3, -1},
                        {0, 3, 4, -1},
                        {3, 4, 5, -1},
                        {2, 4, 6, -1}};
	cross[0]=1; //Set square 0 to 1

//try the 1d approach, columns are squares, rows are values

	//New square
	//while(true){
        while(square<8){
            if(wasUsed(cross, value)){
                    cout << "$$$$$$$";
                value++;
            }
            if(ok(cross, adjacents, square, value)){
                    cout << "------";
                cross[square]=value;
                value=1;
            }
            else{
                    cout << "******";
                backtrack(square);
                continue;
            }
            square++;
            cout << square << ", " << value << endl;
        }
	//}

	return 0;
}
*/
