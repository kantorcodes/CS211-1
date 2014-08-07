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
        double c = kComplex.r;
        double b = i;
        double d = kComplex.i;
        Complex complex;
        complex.r = a+c;
        complex.i = b+d;
        return complex;
    }

    //overloaded subtract function for Complex – should return Complex
    //(a+bi) - (c+di) = (a-c) + (b-d)i
    Complex operator-(Complex kComplex){
        double a = r;
        double c = kComplex.r;
        double b = i;
        double d = kComplex.i;
        Complex complex;
        complex.r = a-c;
        complex.i = b-d;
        return complex;
    }

    //overloaded multiply function for Complex – should return Complex
    //(a+bi) (c+di) = (ac-bd) + (bc+ad)i.
    Complex operator*(Complex kComplex){
        double a = r;
        double c = kComplex.r;
        double b = i;
        double d = kComplex.i;
        Complex complex;
        complex.r = a*c - b*d;
        complex.i = b*c + a*d;
        return complex;
    }

    //overloaded divide function for Complex – should return Complex
    //http://upload.wikimedia.org/math/c/4/8/c4822340ecad680d1556485a55e91f66.png
    Complex operator/(Complex kComplex){
        double a = r;
        double c = kComplex.r;
        double b = i;
        double d = kComplex.i;
        Complex complex;
        complex.r = ((a*c)+(b*d))/((c*c)+(d*d));
        complex.i = ((b*c)-(a*d))/((c*c)+(d*d));
        return complex;
    }

    //get and set for both r and i
    int getR(){
        return r;
    }

    int getI(){
        return i;
    }

    void setR(double n){
        r = n;
    }

    void setI(double n){
        i = n;
    }

    friend ostream& operator<<(ostream& os, Complex kComplex);
    friend istream& operator>>(istream& is, Complex kComplex);
};

    //overloaded input and output functions for Complex
    ostream& operator<<(ostream& os, Complex kComplex){
        os << kComplex.r << " + " << kComplex.i << "i";
        return os; //for chaining
    }

    istream& operator>>(istream& is, Complex kComplex){
        is >> kComplex.r >> kComplex.i;
        return is; //for chaining
    }


int main(){
    Complex c;
    c.setR(2);
    c.setI(7);

    Complex d;
    d.setR(3);
    d.setI(2);

    cout << c + d << endl;
    cout << c - d << endl;
    cout << c * d << endl;
    cout << c / d << endl;

    return 0;
}
