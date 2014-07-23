#include <iostream>
using namespace std;
int main(){
    typedef int my_2darray[1][1];
    my_2darray b[3][2];

    //24 bytes; 3 rows * 2 columns * 4 bytes per int = 24 bytes
    cout<<sizeof(b)<<endl;

    //Size of the pointer to the first element
    //On a 32-bit machine, the size of the pointer is 4 bytes
    //On a 64-bit machine, the size of the pointer is 8 bytes
    cout<<sizeof(b+0)<<endl;

    //???
    //Dereference the first element in the array
    //Yields the same result as sizeof(*b)
    //Size of the first row in the array, b[0]
    //b[0] contains two elements, each 4 bytes, so 2*4 = 8 bytes
    cout<<sizeof(*(b+0))<<endl;

    //Address of the first element in the array
    cout<<"The address of b is: "<<b<<endl;

    //Address of the second row in the array
    //8 byte different between the address of the first row and the address of the second row
    cout<<"The address of b+1 is: "<<b+1<<endl;

    //Derefencing an array
    //In this case, the array is a 1D array; a row in a 2D array
    //Much like *b, this returns a pointer because an array name is actually a pointer to the first element in the array
    cout<<"*(b+1) is: "<<*(b+1)<<endl<<endl;

    //First element in the array. Same as just b
    cout<<"The address of &b is: "<<&b<<endl;

    //24 bytes after the first element
    //When adding 1 to a pointer, the pointer is made to point to the following element of the same type,
    //In other words, when you add to or subtract from a pointer, the amount by which you do that is multiplied by the size of the type of the pointer.
    //Therefore adding 1 here actually adds the size in bytes of the type pointed to
    //In this case, b is a 2D array with a size of 24 bytes
    cout<<"The address of &b+1 is: "<<&b+1<<endl<<endl;

    return 0;
}
