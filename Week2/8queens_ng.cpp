#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;


bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
};

void backtrack(int &col){
    col--;
    if(col==-1) exit(1);
};

void print(int q[]){
    static int count =0;
    cout<< ++ count<<endl<<endl;
    int i;
    for(i=0; i<8; i++)
    cout<<q[i]<<" ";
    cout<<endl<<endl;
};

int main(){
    int q[8]; q[0]=0;
    int c=0;
    bool from_backtrack=false;

    while(true){
        while(c<8){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<8){
                q[c]++;
                if(q[c]==8){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        print(q);
        backtrack(c);
        from_backtrack=true;
    }
    return 0;
}
