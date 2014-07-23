#include <iostream>
using namespace std;

void f(int i){
    if(i == 4||i == 5) return; //if assignment, e.g. (i=4||i=5), then no output is produced; those statements would always resolve to true
    cout << "hello world\n" ;
}

int main(){
    f(3);
    f(4);
    f(5);
    return 0;
}
