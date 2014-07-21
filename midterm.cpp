#include <iostream>
using namespace std;

bool leapyear(int y){
    return (y%4==0&&y%100!=0)||(y%100==0&&y%400==0);
}

int main(){
    cout << leapyear(2012)<<endl;
    cout << leapyear(2100)<<endl;
    return 0;
}
