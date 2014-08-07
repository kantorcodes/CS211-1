/*
What does function r do? Explain fully.
*/

//Function r reverses array x from the index "from" to the index "to".
//For example, provided x = {3, 1, 4, 1, 5}, from = 1, and to = 3,
//r will produce the array x = {3, 5, 1, 4, 1}.

#include <iostream>
using namespace std;

void s(int array[], int i, int j) {
 int temp = array[i];
 array[i] = array[j];
 array[j] = temp;
};

void r(int x[], int from, int to) {
 if (from >= to) return;
 s(x, from, to);
 r(x, from + 1, to - 1);
};

//test
int main(){
    int x[5] = {3, 1, 4, 1, 5};
    r(x, 1, 4);
    for(int i=0; i<5; i++)
        cout << x[i] << " ";
}
