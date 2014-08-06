#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* SORTING FUNCTION CODE NOT VISIBLE */
vector<int> merge(vector<int> a, vector<int> b){
    vector<int> merged; // merged vector
    // pushing all the elements of vector 'a' into vector 'merged'
    while (!a.empty()){
        merged.push_back(a.back());
        a.pop_back();
    }

    // pushing all the elements of vector 'b' into vector 'merged'
    while (!b.empty()){
        merged.push_back(b.back());
        b.pop_back();
    }

    // sorting function found in algorithm library of C++
    int size = merged.size(); // size of vector 'merged'
    sort(merged.begin(), merged.begin()+size);
    return merged;
}

int main(){

}

/* SORTING FUNCTION CODE VISIBLE
vector<int> merge(vector<int> a, vector<int> b){
    vector<int> merged; // merged vector
    int i = 0, j = 0; // index variables

    // checking and pushing the smaller element into vector 'merged'
    while (!a.empty() || !b.empty()){
        // if element of vector 'a' is smaller than or equal to that of 'b'
        if (a[i] <= b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }

    // pushing the remaining elements of vector 'a' into vector 'merged'
    while (i < a.size()){
        merged.push_back(a[i]);
        i++;
    }

    //pushing the remaining elements of vector 'b' into vector 'merged'
    while (j < b.size()){
        merged.push_back(b[j]);
        j++;
    }

    return merged;
}
*/
