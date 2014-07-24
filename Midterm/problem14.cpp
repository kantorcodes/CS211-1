#include <iostream>
using namespace std;

int fib(int n){
    static int memo[100]={0, 1, 1};
    if(n==1||n==2) return 1;
    if(memo[n]!=0) return memo[n];
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
}

int main(){
	for(int i=1; i<=75; i++){
		cout << fib(i) << endl;
	}
	return 0;
}
