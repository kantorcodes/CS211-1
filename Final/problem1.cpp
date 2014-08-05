/*
1. For the SA class in the handouts, write operator<<(…)
*/

//overload the << operator
ostream& operator<<(ostream& os, SA s){

    int size=s.high-s.low+1; //size = length of the SafeArray

    //for every element in the SafeArray,
    for(int i=0; i<size; i++)
        cout<<s.p[i]<<endl; //print it

    //return the ostream so that we can perform chaining
    return os;
};
