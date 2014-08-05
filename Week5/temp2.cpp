//Sample Final Exam: Question 4 RAT
//Kin Zhao

#include <iostream>
using namespace std;

void reduce(int n, int d)
{
// first find which one is bigger out of n and d.
int max;
if(n > d)
	max = n;
else
	d = n;
int gcd = 1;
// intialize gcd with 1.
for(int i = max; i >= 1; i--)
{
// start checking for big factor that commonly divides n and d;
// once it's found break it.
if(n % i == 0 && d % i == 0) { gcd = i; break; }
}
// dividing both numerator and denominator with gcd.
n = n / gcd;
d = d / gcd;

cout << "n: " << n << endl << "d: " << d;
}

int main(){
    reduce(346,1024);
}
