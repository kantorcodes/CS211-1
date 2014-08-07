//6. Given the following main function:
//remove the first digit of a number

//Write a recursive function removeFirst(n) to remove the first digit of a number
int removeFirst(int n){
    if(n/10==0) return 0;
    else return 10*removeFirst(n/10)+(n%10);
};

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter a number greater than 0: ";
    cin >> n;
    m = removeFirst(n);
    cout << m << endl;
    return 0;
}

