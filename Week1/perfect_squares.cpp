/*
Write a program to print perfect squares from 1^2, 2^2, ... N^2,
where the user is asked to enter a positive integer for N.
*/
#include <iostream>
using namespace std;
int main(){
		int n = 0;
		cout << "Please enter a positive integer: ";
		cin >> n;
		//cout << n << endl;
		cout << "Perfect squares: ";
		for(int i=1; i<=n; i++){
			cout << i*i << endl;
		}
        return 0;
}


