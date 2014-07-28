#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> t[3]; // three towers A,B,C represented as an array of 3 vectors
    int n, candidate,to, from, move=0; // move counts the move number
    cout<<"Please enter a number of rings to move: ";
    cin>>n;
    cout<<endl;

    //intitialize the 3 towers
    for(int i=n+1;i>=1;i--)
        t[0].push_back(i);
        t[1].push_back(n+1);
        t[2].push_back(n+1);

    // initialize towers and candidate
    if((n%2)!=0){
        from=0;
        to=1;
        candidate=1;
    }
    else{
        from=0;
        to=2;
        candidate=1;
    }

    while(t[1].size()<n+1){ // there are still rings to transfer to tower B = t[1]
        cout<<"move number "<<++move<<": Transfer ring "<<candidate<<
        " from tower "<< char(from+65)<<" to tower "<<char(to+65)<<endl;

        t[to].push_back(t[from].back());
        t[from].pop_back();

        //from tower = tower with candidate; smallest available ring which was not just moved
        //tower with the just-moved ring is the current to tower
        if(t[(to+1)%3].back()<t[(to+2)%3].back()) from=(to+1)%3;
        else from=(to+2)%3;

        //odd number of rings
        if((n%2)!=0){
            //"to" = closest tower on which the ring can be placed
            if(t[from].back()<t[(from+1)%3].back()) to=(from+1)%3;
            else to=(from+2)%3;
        }

        //even number of rings
        else{
            if(t[from].back()<t[(from+2)%3].back()) to=(from+2)%3;
            else to=(from+1)%3;
        }

        candidate=t[from].back();
    }
    return 0;
}

