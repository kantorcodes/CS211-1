#include <iostream>
using namespace std;

int into(int i, int j){
    if(i==0||j==0) return 1;
    return into(i-1, j) + into(i, j-1);
}

int main(){
    cout << into(5, 5);
    return 0;
}
