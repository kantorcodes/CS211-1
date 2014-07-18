//Raveen Kanagaratnam
//CS211

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool ok(int q[], int col)
{
	for(int i=0; i<col; i++)
	{
		if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
	}
	return true;
}

void backtrack(int &col)
{
	col--;
	if(col==-1) exit(1);
}

void print(int q[])
{
	static int count =0;
	cout<< ++ count<<endl<<endl;
	int i;
	for(i=0; i<8; i++)
	{
		cout<< q[i] << " ";
	}
	cout<<endl<<endl;
}

int main()
{
	int i,j,k,l;
	typedef char box[5][7];
	box bb,wb,wq,bq,*board[8][8];
	int q[8],c=1;
	q[0]=0;
	bool from_backtrack=false;
	while(true)
	{
		while(c<8)
		{
			if(!from_backtrack)
			{ 
				q[c]=0;
				from_backtrack=false;
			}
			while(q[c]<8) 
			{
				if(ok(q, c)) break;
				else q[c]++;
			}
			if(q[c]==8) 
			{
				backtrack(c);
				q[c]++;
				from_backtrack=true;
			}
			else
			{
				c++;
				from_backtrack=false;
			}
		}  
		print(q);
		//fill inbb=black box and wb=whitebox
		for(i=0;i<5;i++)
		{
			for(j=0;j<7;j++)
			{ 
				wb[i][j]=' ';
				bb[i][j]=char(219);
			}
		}

		//fill in wq=whitequeen in blackbox and bq=blackqueen in whitebox
		for(i=0;i<5;i++) 
		{  
			for(j=0;j<7;j++)
			{
				if(j==0||i==0||j==6||i==4||i==1&&(j==2||j==4))
				{
					wq[i][j]=char(219);
					bq[i][j]=' ';
				}
				else
				{
					wq[i][j]=' ';
					bq[i][j]=char(219);
				} 
			}
		}
		
		//fill board with pointers to bb and wb in alternate positions
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if((i+j)%2==0)
				{
					board[i][j]=&wb;
				}
				else
				{
					board[i][j]=&bb;
				}
			}
		}
		for(i=0;i<8;i++)
		{
			if((i+q[i])%2==0)
			{
				board[q[i]][i]=&wq;
			}
			else
			{
				board[q[i]][i]=&bq;
			}
		}
		//print the board via the pointers in array board
		//first print upper border
		cout<<" ";
		for(i=0;i<7*8;i++)
			cout<<'_';
		cout<<endl;

		//now print the board
		for(i=0;i<8;i++)
		{
			for(k=0;k<5;k++)
			{
				cout<<" "<<char(20); //print left border
				for(j=0;j<8;j++) 
				{
					for(l=0;l<7;l++)
					{
						cout<<(*board[i][j])[k][l];
					}
				}
				cout<<char(20)<<endl; // at end of line print bar and then newline
			}
		}
		//before exiting print lower border
		cout<<" ";
		for(i=0;i<7*8;i++)
		{
			cout<<char(20);
		}
		cout<< endl;

	backtrack(c);
	q[c]++;
	from_backtrack=true;
	}
	return 0;
}
