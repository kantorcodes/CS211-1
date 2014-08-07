/*
4. Write a stack class using an array (from the heap) to implement it. What is a “stack”? We
saw the run-time stack in class. It is a data structure that allows us to “push” an element to the
“top”, to “pop” from the “top”. In fact, for the no-recursive towers, we used a vector as a stack.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class stack{
    private:
        int top; // top is the index into the array for the current top
        int * p; // p is a pointer into the heap where the stack is actually located. Just like for SA class.
        int size; // size of the array allocated for the stack
    public:

        //constructor
        //a stack to hold 100
        stack(){
            top = 0;
            p = new int[100];
            size = 100;
        };

        //constructor
        //a stack to hold n elements
        stack(int n){
            top = 0;
            p = new int[n];
            size = n;
        }

        //destructor
        ~stack(){
            delete[]p;
        };

        bool empty(){
            return top==0;
        };

        void push(int n){
            if(top+1 >= size) exit(1); //don’t forget to test if stack is full
            else{
                p[top] = n;
                top++;
            }
        };

        int pop(){
            if(size==0||top<0) exit(1); //don’t forget to test if the stack is empty
            else{
                top--;
                return p[top];  //return and remove the “top” element of the stack.
            }
        };
};

//Test it with the following main function:
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i=0; i<3; i++)
    cout<<s.pop(); // should print 3,2 1
    cout<<s.empty();
    return 0;
}
