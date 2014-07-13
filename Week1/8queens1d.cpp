#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int q[8], c=0, solution=1; //Initialize arrays
	q[0]=0; //Place a queen in the upper left corner
	
	NC: c++;
	if(c==8) goto PRINT;
	q[c]=-1;

	NR: q[c]++;
	if(q[c]==8) goto BACKTRACK;

	//Test to ensure that a queen can be placed
	for(int i=0; i<c; i++){
		if((q[i]==q[c])||(abs(q[c]-q[i])==(c-i))) goto NR;
	}
	
	goto NC;
	
	BACKTRACK: c--;
	if(c==-1) return 0;
	goto NR;

	PRINT: cout << "SOLUTION " << solution << endl;
	for(int row=0; row<8; row++){
		for(int column=0; column<8; column++){
			if(q[column]==row) cout << "1 ";
			else cout << "0 ";	
		}
		cout << endl;
	}
	cout << endl;
	solution++;
	goto BACKTRACK;
}
