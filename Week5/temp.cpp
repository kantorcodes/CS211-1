#include <iostream>
#include <cstdlib>
using namespace std;

int k;

bool ok(int q[], int c, int n){
    for(int i = 0 ;i < c; i++) {

        int i1 = q[i]/n;
        int j1 = q[i]%n;
        int i2 = q[c]/n;
        int j2 = q[c]%n;

        if(i1 + j1 == i2 + j2)
            return false;
        if(i1 - j1 == i2 - j2)
            return false;
    }
    return true;
};


void backtrack(int &col){
   col--;
       if(col==-1) {
		system("PAUSE"); exit(1);
	   }

}

void print(int q[], int c){
    cout<<endl<<"solution number: "<<c<<endl<<endl;
    if(c<1)
        cout<<" no solutions ";
    for(int i = 0; i < k; i++){
        cout<<q[i]<<" ";
    }
    cout<<endl<<endl;
};

int main(){
    int n;
    cout<<"Please enter the size of the board:"<<endl;
    cin>>n;
    cout<<"Please enter the number of bishops: "<<endl;
    cin>>k;


        int* q = new int[k];
        int c = 0;
        q[c] = 0;
        int count = 0;

        while(1){
            while(c<k){

                while(q[c]<n*n){
                    if(ok(q,c, n))
                        break;  //if the current configuration is ok, then stop increasing the box the current bishop is in
                    else
                        q[c]++; //increase the box the current bishop is in
                }

                if(q[c]==n*n){ //if we're in the last box and we still haven't placed a bishop, then backtrack
                    backtrack(c, count, k);
                    q[c]++;
                }
                else{
                    int temp = q[c]; //we found a solution, so store the box the current bishop is in
                    c++; //go to the next bishop
                    q[c] = temp; //set the current box to the previous box; start from there
                }
            }
            count++;
			print(q, count);
            backtrack(c);
            q[c]++;
        }
        delete[] q;

system("PAUSE");
return 0;
}
