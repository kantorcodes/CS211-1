#include <iostream>
#include <assert.h>
using namespace std;

bool leapyear(int y){
    return (y%4==0&&y%100!=0)||(y%100==0&&y%400==0);
}

int main(){
    assert(!leapyear(1805));
    assert(!leapyear(2002));
    assert(!leapyear(2222));
    assert(!leapyear(2226));
    assert(leapyear(1808));
    assert(leapyear(2324));
    assert(leapyear(2000));
    assert(leapyear(2400));
    return 0;
}
