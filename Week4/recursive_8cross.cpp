#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int cross[8],int c){
         int a[8][4]={{-1},{0,-1},{1,-1},{0,1,2,-1},{1,2,3,-1},{0,3,4,-1},{3,4,5,-1},{2,4,6,-1}};
         for(int i=0;i<c;i++){
                if(cross[i]==cross[c]) return false;
         }
         for(int i=0; a[c][i]!=-1;i++){
                if(abs(cross[c]-cross[a[c][i]])==1) return false;
         }
         return true;
}

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
