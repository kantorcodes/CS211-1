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
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int min(vector<int> x){
    int min = INT_MAX;
    for(int i=0; i<x.size(); i++){
        if(x[i]<min) min=x[i];
    }
    return min;
}

vector<int> reverse(vector<int> x){
    for(int i=0; i<x.size()/2; i++){
        int temp = x[i];
        x[i] = x[x.size()-i-1];
        x[x.size()-i-1]=temp;
    }
    return x;
}

//does not account for ascending numbers outside of a certain index, e.g.
//a: 2, 3, 7, 12
//b: 1, 8, 10, 14
//would produce the output 1, 2, 3, 8, 7, 10, 12, which is incorrect
vector<int> stupid_merge( vector<int> a, vector<int> b){
    int max_size = (a.size()>b.size())?a.size():b.size(); //ternary conditional to assign max_size
    vector<int> merged;
    for(int i=0; i<max_size; i++){

        //in case one vector is larger than the other
        if(i>a.size()-1){
            merged.push_back(b[i]);
            continue;
        }
        if(i>b.size()-1){
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
    int max_size = (a.size()>b.size())?a.size():b.size(), min_value = 0;
    //reverse the vectors so that we can use pop_back()
    a = reverse(a);
    b = reverse(b);
    vector<int> merged;

    for(int i=max_size-1; i>0; i--){
        if(i>a.size()-1){
            merged.push_back(b[i]);
            b.pop_back();
            continue;
        }
        if(i>b.size()-1){
            merged.push_back(a[i]);
            a.pop_back();
            continue;
        }

        if(min(a)<min(b)){
            merged.push_back(min(a));
            a.pop_back();
        }
        if(min(b)<min(a)){
            merged.push_back(min(b));
            b.pop_back();
        }
    }

    return merged;
}

int main(){
    vector<int> a = {2, 4, 6, 8};
    vector<int> b = {1, 3, 7, 10, 13};
    vector<int> n;

    n = stupid_merge(a, b);
    for(int i=0; i<n.size(); i++) cout << n[i] << ", ";

    cout << endl;

    n = unsorted_merge(a, b);
    for(int i=0; i<n.size(); i++) cout << n[i] << ", ";

    return 0;
}

