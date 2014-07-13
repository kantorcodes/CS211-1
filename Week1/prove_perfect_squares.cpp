/*
Write a program to find and print the first perfect square (i*i) whose last two digits are both odd.
Prove that, in theory, any program that you write to solve the above problem will
run for infinite time.
*/

#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;

int main(){
    int i = 4;
    int square = 16;
    int isTensOdd = 0;
    int isOnesOdd = 0;
   
    while(true){
        square = i*i;

        if(i>=SHRT_MAX || square/abs(square)==-1){
            cout << "This value does not exist." << endl;
            break;
        }

        isTensOdd = ((square-(square%10))%20)%9; //Map whether the second-to-last digit is odd to an integer
        isOnesOdd = square%2; //Map whether the last digit is odd to an integer value, 0 (even) or 1 (odd)

        if(isTensOdd && isOnesOdd){
            cout << square << endl;
            break; //Exit the loop if the desired perfect square is found
        }

        i++; //Increment i
    }
    return 0;
}
		
/*
A 2- or more- digit number n can be expressed as 1x + 10y + 100z + ...
Ignoring all terms above 10y (since they do not influence the second to last digit),
n = x + 10y and n^2 = 100y^2 + 20xy + x^2.
For any y where y>0, 100y^2 will have more than two digits, so that term is ignored.
The last term of 20xy + x^2, being x^2, can only be odd if x is odd, since an even number
squared creates an even perfect square.
Thus 20x will always be even, since an even number times an odd number will always be even.
With 20x being even there is no value of y which can make 20xy, which provides the second to last 
digit, odd.
*/
