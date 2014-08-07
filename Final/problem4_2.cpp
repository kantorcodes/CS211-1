//4. Write the function to reduce the numerator and denominator in the Rat class to lowest terms.

#include <iostream>
using namespace std;

void reduce(int &n, int &d){
    int min = (n<d)?n:d;
    for(int i=min; i>0; i--){
        if(n%i==0 && d%i==0){
            n /= i;
            d /= i;
            break;
        }
    }
}

int main(){
    int n = 24, d = 1024;
    reduce(n, d);
    cout << n << endl << d;
}
