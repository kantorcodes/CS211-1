/*
Write a program to find and print the first perfect square (i*i) whose last
two digits are both odd.
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

        isTensOdd = ((square-(square%10))%20)%9; //Map whether the second-to-last digit is odd to an integer value, 0 (even) or 1 (odd)
        isOnesOdd = square%2; //Map whether the last digit is odd to an integer value, 0 (even) or 1 (odd)

        if(isTensOdd && isOnesOdd){
            cout << square << endl;
            break; //Exit the loop if the desired perfect square is found
        }

        i++; //Increment i
    }
    return 0;
}
