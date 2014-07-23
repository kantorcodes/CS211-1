#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
};

void print(int *q){
    static int count=0;
    cout << ++count << endl;
    for(int k=0; k<8; k++) cout << q[k];
    cout << endl;
};

void move(int* q, int i){
    if(i==8){
        print(q);
        return;
    }

    for(int j=0; j<8; j++){
        q[i]=j;
        if(ok(q,i)) move(q,i+1);
    }
};

int main(){
    int q[8];
    move(q,0);
    return 0;
}
