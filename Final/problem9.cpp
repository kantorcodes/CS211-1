/*
9. Let a and b be two vector<int>. i.e. a and b are two vectors, of possibly different sizes, containing integers.
Further assume that in both a and b the integers are sorted in ascending order.
Write a function:
vector<int> merge( vector<int> a, vector<int> b)
that will merge the two vectors into one new one and return the merged vector,
By merge we mean that the resulting vector should have all the elements from a and b, and all its elements
should be in ascending order.
For example:
a: 2,4,6,8
6
b: 1,3,7,10,13
the merge will be: 1,2,3,4,6,7,8,10,13
Do this in two ways. In way 1 you cannot use any sorting function. In way 2 you must.
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int min(vector<int> x){
    int min = INT_MAX;
    for(int i=0; i<x.size(); i++)
        if(x[i]<min) min=x[i];
    return min;
}

//does not account for ascending numbers outside of a certain index, e.g.
//a: 2, 3, 7, 12
//b: 1, 8, 10, 14
//would produce the output 1, 2, 3, 8, 7, 10, 12, which is incorrect
vector<int> stupid_merge( vector<int> a, vector<int> b){
    int min_a = INT_MAX, min_b = INT_MAX, max_size = (a.size()>b.size())?a.size():b.size(); //ternary conditional to assign max_size
    vector<int> merged;
    for(int i=0; i<max_size; i++){

        //in case one vector is larger than the other
        if(i>a.size()){
            merged.push_back(b[i]);
            continue;
        }
        if(i>b.size()){
            merged.push_back(a[i]);
            continue;
        }

        //since a and b are in ascending order, push back onto merged in a specific order
        if(a[i]<b[i]){
            merged.push_back(a[i]);
            merged.push_back(b[i]);
        }
        else{
            merged.push_back(b[i]);
            merged.push_back(a[i]);
        }
    }
    return merged;
}

vector<int> unsorted_merge( vector<int> a, vector<int> b){

}

