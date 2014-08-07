/*
3. In lecture we went over the Rat class. Here the question is to write a Complex ( imaginary number ) class;
*/

#include <iostream>
using namespace std;

class Complex {

    //private data members; only accessible within the class
    private:
    double r; //real
    double i; //imaginary (coefficient)

    //public functions; accessible outside of the class
    public:

    //constructor
    Complex(){
        r = 0;
        i = 0;
    }

    //overloaded add function for Complex – should return Complex
    //(a+bi) + (c+di) = (a+c) + (b+d)i
    Complex operator+(Complex c){
        Complex d;
        d.r = r + c.r;
        d.i = i + c.i;
        return d;
    }

    //overloaded subtract function for Complex – should return Complex
    //(a+bi) - (c+di) = (a-c) + (b-d)i
    Complex operator-(Complex c){
        Complex d;
        d.r = r - c.r;
        d.i = i - c.i;
        return d;
    }

    //overloaded multiply function for Complex – should return Complex

     overloaded divide function for Complex – should return Complex
     get and set for both r and i
     overloaded input and output functions for Complex
};
