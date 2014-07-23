#include <iostream>
#include <cstdlib>
using namespace std;

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
    cout << "SOLUTION " << ++count << endl;
    cout << "  " << q[1] << " " << q[2] << endl;
    cout << q[0] << " " << q[3] << " " << q[4] << " " << q[7] << endl;
    cout << "  " << q[5] << " " << q[6] << endl << endl;
}

void move(int* q, int i){
    if(i==8){
        print(q);
        return;
    }

    for(int j=1; j<=8; j++){
        q[i]=j;
        if(ok(q,i)) move(q,i+1);
    }
};

int main(){
    int q[8];
    move(q,0);
    return 0;
}
