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
    Complex operator+(Complex kComplex){
        double a = r;
        double c = c.r;
        double b = i;
        double d = c.i;
        Complex complex;
        complex.r = a+c;
        complex.i = b+d;
        return Complex;
    }

    //overloaded subtract function for Complex – should return Complex
    //(a+bi) - (c+di) = (a-c) + (b-d)i
    Complex operator-(Complex kComplex){
        double a = r;
        double c = c.r;
        double b = i;
        double d = c.i;
        Complex complex;
        complex.r = a-c;
        complex.i = b-d;
        return complex;
    }

    //overloaded multiply function for Complex – should return Complex
    //(a+bi) (c+di) = (ac-bd) + (bc+ad)i.
    Complex operator*(Complex kComplex){
        double a = r;
        double c = c.r;
        double b = i;
        double d = c.i;
        Complex complex;
        complex.r = a*c - b*d;
        complex.i = b*c + a*d;
        return complex;
    }

    //overloaded divide function for Complex – should return Complex
     get and set for both r and i
     overloaded input and output functions for Complex
};
