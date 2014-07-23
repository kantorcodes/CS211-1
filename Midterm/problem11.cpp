/*
Write a function
int number_of_primes(int from, int to)
that returns the number of prime numbers between from and to.
*/

#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<n/2+1; i++){
        if(n%i==0) return false;
    }
    return true;
};

int number_of_primes(int from, int to){
    int counter=0;
    for(int i=from; i<to; i++){
        if(isPrime(i)) counter++;
    }
    return counter;
};

int main(){
    cout << number_of_primes(2,1000); //168
    return 0;
};
