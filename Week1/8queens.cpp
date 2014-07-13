#include <fstream>
#include <iostream>
using namespace std;

int main(){
	//ofstream fout;
        //fout.open("output.txt");

	int b[8][8]={0}, r, c=0, solution=1;
	b[0][0]=1;
	
	NC: c++; //Next column
	if(c==8) goto PRINT; //Solution found 	
	r=-1;

	NR: r++;
	if(r==8) goto BACKTRACK;
	 
	//Row test
	for(int i=0; i<c; i++){
		if(b[r][i]==1) goto NR;
	}

	//Up-diagonal test
	for(int j=1; ((c-j)>=0)&&((r-j)>=0); j++){
		if(b[r-j][c-j]==1) goto NR;
	}

	//Down-diagonal test
	for(int k=1; ((c-k)>=0)&&((r+k)<8); k++){
		if(b[r+k][c-k]==1) goto NR;
	}

	//No conflict
	b[r][c]=1;
	goto NC;

	BACKTRACK: //Backtrack
	c--; //Move back 1 column
	if(c==-1) return 0; //Check if we're done
	r = 0; //Find the queen
	while(b[r][c]!=1) r++;
	b[r][c]=0;
	goto NR;

	PRINT:
	cout << "SOLUTION " << solution << ": " << endl; 
	for(int row=0; row<8; row++){
		for(int column=0; column<8; column++){
			cout << b[row][column] << " ";
		}
                cout << endl;
	}
	cout << endl;
	solution++;
	goto BACKTRACK;

	//fout.close();
}
