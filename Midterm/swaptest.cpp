#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a=3, b=6;
    int* ptr_a=&a;
    int* ptr_b=&b;
    swap(&a,&b);
    cout << a << ", " << b << endl;
    swap(ptr_a, ptr_b);
    cout << a << ", " << b << endl;
    return 0;
}
