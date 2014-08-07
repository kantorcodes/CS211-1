/*
4. Write a stack class using an array (from the heap) to implement it. What is a “stack”? We
saw the run-time stack in class. It is a data structure that allows us to “push” an element to the
“top”, to “pop” from the “top”. In fact, for the no-recursive towers, we used a vector as a stack.
*/

class stack{
    private:
        int top; // top is the index into the array for the current top
        int * p; // p is a pointer into the heap where the stack is actually located. Just like for SA class.
        int size; // size of the array allocated for the stack
    public:

        //constructor
        //a stack to hold 100
        stack(){
            top = 99;
            p = new int[100];
            size = 100;
        };

        //constructor
        //a stack to hold n elements
        stack(int n){
            top = n-1;
            p = new int[n];
            size = n;
        }

        //destructor
        ~stack(){
            delete[]p;
        };
        bool empty();
        void push( int ); // don’t forget to test if stack is full
        int pop(); // return and remove the “top” element of the stack.
        // don’t forget to test if the stack is empty
}

//Test it with the following main function:
int main(){
    stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    for (i=0; i<3; i++)
    cout<<s.pop(); // should print 3,2 1
    return 0;
}
