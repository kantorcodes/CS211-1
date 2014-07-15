#include <iostream>
#include<cstdlib> 
#include <cmath> 
using namespace std; 
 
bool ok(int q[], int col){ 
 for(int i=0; i<col; i++) 
 if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false; 
 
 return true; 
}; 
 
void backtrack(int &col){ 
 col--; 
cout<<"backtrack to column"<<col<<endl; 
if(col==-1) 
 {system("PAUSE"); exit(1);} 
}; 
 
void print(int q[]){ 
 static int count =0; 
 cout<< ++ count<<endl<<endl; 
 int i; 
 for(i=0; i<8; i++) 
 cout<<q[i]<<" "; 
 cout<<endl<<endl; 
}; 
 
 
 int  main(){ 
 int q[8]; q[0]=0;
 int c=1;

 while (c<8){
	while (ok(q, c)==false){
		q[c]++;
		//cout<<"print out NR_col"<<c<<" row"<<q[c]<<endl;
		if (q[c]==8) backtrack(c);
		}
	c++;
	//cout<<"printout next column"<<c<<endl;
if (c==8){
	print(q);

}
}//closes while (c<8)
	

return 0;
}
