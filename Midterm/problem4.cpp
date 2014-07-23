#include <assert.h>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
   _ _
 _|1|2|_
|0|3|4|7|
  |5|6|

*/

bool ok(int q[8], int square){
    static int adjacents[8][4]={{-1, -1, -1, -1},
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

int main(){
    int a[8]={1,1,1,1,1,1,1,1};
    int b[8]={1,2,3,4,5,6,7,8};
    int c[8]={6,3,5,0,7,2,4,1};
    assert(!ok(a,7));
    assert(!ok(b,7));
    assert(ok(c,7));
    return 0;
}
