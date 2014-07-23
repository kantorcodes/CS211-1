#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int col){

    int mp[3][3]={{0, 2, 1},
                {0, 2, 1},
                {1, 2, 0}};
    int wp[3][3]={{2, 1, 0},
                {0, 1, 2},
                {2, 0, 1}};

    int current_man, current_woman, new_man, new_woman;

    for(int i=0; i<col; i++){
        current_man=i;
        current_woman=q[i]; //woman assigned to man i
        new_man=col;
        new_woman=q[col];
        if(new_woman==current_woman) return false;
    }

    for(int i=0; i<col; i++){
        current_man=i;
        current_woman=q[i]; //woman assigned to man i
        new_man=col;
        new_woman=q[col];

        if(mp[current_man][current_woman]>mp[current_man][new_woman]&&
           wp[new_woman][current_man]<wp[new_woman][new_man]) return false;

        if(mp[new_man][current_woman]<mp[new_man][new_woman]&&
           wp[current_woman][new_man]<wp[current_woman][current_man]) return false;
    }

    return true;
};

void print(int q[]){
    static int count=0;
    cout << "SOLUTION " << ++count << endl;
    cout << "Man Woman" << endl;
    for(int i=0; i<3; i++){
        cout << " " << i << "    " << q[i] << endl;
    }
    cout << endl << endl;
};

void move(int* q, int i){
    if(i==3){
        print(q);
        return;
    }

    for(int j=0; j<3; j++){
        q[i]=j;
        if(ok(q,i)) move(q,i+1);
    }
};

int main(){
    int q[3];
    move(q,0);
    return 0;
}
