#include <iostream>
#include <cstdlib>
using namespace std;

int k;

bool ok(int q[], int c, int n){
    for(int i = 0 ;i < c; i++) { //for every bishop

        //i1 + j1 =
        int i1 = q[i]/n; //square/gridsize
        int j1 = q[i]%n; //square%gridsize

        //i2 + j2 =
        int i2 = q[c]/n; //currentsquare/gridsize
        int j2 = q[c]%n; //currentsquare%gridsize

        if(i1 + j1 == i2 + j2)
            return false;
        if(i1 - j1 == i2 - j2)
            return false;
    }
    return true;
};

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(col-i==abs(q[col]-q[i])) return false;
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

/*
For each of the k bishops, (69)
look at all the possible boxes the bishop could be in (71)
If it's ok to put bishop c in box q[c], (72)
    then do so, and go to the next bishop. (82)
        If there is no next bishop, then one or more of the bishops are causing an issue, so backtrack (78)
        But if there is no next bishop and the solution was okay, then break out of the whole loop (q[c]<n*n still satisfied) and do the after-all-bishops sequence. (73)
If it's not ok to put bishop c in box q[c], (74)
    then go to the next box. (75)
If a solution was found, then you don't want to go back a box (like going back a column), so store q[c] and go to the next bishop. (83)
When a solution is found, q[c]++ (akin to incrementing the first row in the 8 queens problem), i.e. the starting point. (91)
*/

        while(1){
            while(c<k){ //while current bishop is less than # bishops; solution not yet found

                while(q[c]<n*n){ //while current box is less than # boxes; solution not yet found
                    if(ok(q,c,n))
                        break;  //if the current configuration is ok, then stop increasing the box the current bishop is in
                    else
                        q[c]++; //increase the box the current bishop is in
                }

                if(q[c]==n*n){ //if we're in the last box and we still haven't placed a bishop, then backtrack
                    backtrack(c);
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
            backtrack(c); //go back a bishop
            q[c]++; //increase the box the bishop is in
        }
        delete[]q;

system("PAUSE");
return 0;
}
