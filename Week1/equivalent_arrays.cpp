#include <iostream>
using namespace std;
            
//Check if two arrays are identical
bool identical(int a[], int b[], int n){
    bool isIdentical = true;
    
    //Compare each value in each array, and test whether they're equal
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            isIdentical = false;
            break;
        }
    }
    return isIdentical;
}

bool equivalent(int a[], int b[], int n){
    bool isEquivalent = false;
    int temp;
    
    //Test for equivalent arrays
    for(int i=0; i<n; i++){   
        //Right shift the elements in newArray
        for(int j=0; j<n; j++){
            temp = b[n-1];
            b[n-1] = b[j];
            b[j] = temp;
        }
		//If two arrays are identical, then stop the program
        if(identical(a, b, n)){
            isEquivalent = true;
            break;
        }
    }
    return isEquivalent;
}

int main(){
	//Test case 1: Should output "Not equivalent"
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 1, 2};
    if(equivalent(a, b, 5)) cout << "Equivalent" << endl;
    else cout << "Not equivalent" << endl;
    
    //Test case 2: Should output "Not equivalent"
    int c[] = {1, 2, 3, 5, 4};
    int d[] = {3, 4, 5, 1, 2};
    if(equivalent(c, d, 5)) cout << "Equivalent" << endl;
    else cout << "Not equivalent" << endl;
            
    return 0;
}
