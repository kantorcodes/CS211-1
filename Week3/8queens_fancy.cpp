#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void print(int q[]){
	static int solution=0;
	int i,j,k,l;

	typedef char box[5][7];

	box bb,wb,bq,wq,*board[8][8];
	char H=char(219);

	//create black queen image
	/*
	bq[0]={' ',' ',' ',' ',' ',' ',' '};
	bq[1]={' ', H ,' ', H ,' ', H ,' '};
	bq[2]={' ', H , H , H , H , H ,' '};
	bq[3]={' ', H , H , H , H , H ,' '};
	bq[4]={' ',' ',' ',' ',' ',' ',' '};
    */
    //create black queen image without direct assignment from initializer list
    for(i=0;i<5;i++){
        for(j=0;j<7;j++){
            if(i==0||i==4) bq[i][j]=' ';
            if(i==1){
                if(j%2==0) bq[i][j]=' ';
                else bq[i][j]=H;
            }
            if(i==2||i==3){
                if(j==0||j==6) bq[i][j]=' ';
                else bq[i][j]=H;
            }
        }
    }

	//create white queen image by inverting black queen image
	for(i=0;i<5;i++){
		for(j=0;j<7;j++){
			if(bq[i][j]==' ') wq[i][j]=char(219);
			if(bq[i][j]==H) wq[i][j]=' ';
		}
	}

	//fill in bb=black box and wb=whitebox
	for(i=0;i<5;i++)
		for( j=0;j<7;j++){
			wb[i][j]=' ';
			bb[i][j]=char(219);
		}

	//fill board with pointers to bb and wb in alternate positions
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if((i+j)%2==0)
			board[i][j]=wb;
			else board[i][j]=&bb;

	// print the board via the pointers in array board
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(q[j]==i){
				if((board[i][j])==&wb) board[i][j]=&bq;
				else board[i][j]=&wq;
			}
		}
	}

	// print solution number
	cout << endl << "SOLUTION " << ++solution << endl;

	// first print upper border
	cout<<" ";
	for(i=0;i<7*8;i++)
		cout<<'_';
		cout<<endl;

	// now print the board
	for(i=0;i<8;i++)
		for(k=0;k<5;k++){
			cout<<" "<<char(179); //print left border
			for(j=0;j<8;j++)
				for(l=0;l<7;l++)
					cout<<(*board[i][j])[k][l];
			cout<<char(179)<<endl; // at end of line print bar and then newline
		}

	// before exiting print lower border
	cout<<" ";
	for(i=0;i<7*8;i++)
		cout<<char(196);
		cout<<endl;

    // reset array board
    for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if((i+j)%2==0)
			board[i][j]=&wb;
			else board[i][j]=&bb;
}

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
    return true;
};

void backtrack(int &col){
    col--;
    if(col==-1) exit(1);
};

int main(){
    int q[8]; q[0]=0;
    int c=0;
    bool from_backtrack=false;

    while(true){
        while(c<8){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<8){
                q[c]++;
                if(q[c]==8){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        print(q);
        backtrack(c);
        from_backtrack=true;
    }
    return 0;
}
