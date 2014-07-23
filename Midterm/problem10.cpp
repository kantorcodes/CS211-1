#include <iostream>
using namespace std;

int* return_an_array(int n){
    int counter = 0, num=n;
    while(num){
        num=num/10;
        counter++;
    }

    int i=counter-1;
    int* q = new int[counter];

    while(n/10!=0){
        q[i]=n%10;
        n/=10;
        i--;
    }

    return q;

}

int main(){
    int a = 62354, i=0;
    while(i<5){
        cout << *(return_an_array(a)+i);
        i++;
    }
    return 0;
}
