
#include <cstdlib>
#include <iostream>
using namespace std;
bool ok(int q[8],int c){
    for(int i=0;i<8;i++){
      if(q[i]==q[c]||abs(q[c]-q[i]==c-i)) return false;
    }
    return true;
}
void backtrack(int &c){
    c--;
    if(c==-1) exit(1);
}
int main(int argc,char* argv[]){
    int i,j,k,l;int q[8];int c=0;bool from_backtrack=false;
    typedef char box[5][7];
    box bb,wb,bq,wq,*board[8][8];
    for(i=0;i<5;i++){
       for(j=0;j<7;j++){
          wb[i][j]=' ';
          wq[i][j]=' ';
          bb[i][j]=char(219);
          bq[i][j]=char(219);
       }
    }
    wq[1][1]=char(219);
    wq[2][1]=char(219);
    wq[3][1]=char(219);
    wq[4][2]=char(219);
    wq[1][3]=char(219);
    wq[2][3]=char(219);
    wq[3][3]=char(219);
    wq[4][3]=char(219);
    wq[4][4]=char(219);
    wq[1][5]=char(219);
    wq[2][5]=char(219);
    wq[3][5]=char(219);
    wq[4][5]=char(219);
    bq[1][1]=' ';
    bq[2][1]=' ';
    bq[3][1]=' ';
    bq[4][2]=' ';
    bq[1][3]=' ';
    bq[2][3]=' ';
    bq[3][3]=' ';
    bq[4][3]=' ';
    bq[4][4]=' ';
    bq[1][5]=' ';
    bq[2][5]=' ';
    bq[3][5]=' ';
    bq[4][5]=' ';
    for(i=0;i<8;i++){
       for(j=0;j<8;j++){
           if((i+j)%2==0) board[i][j]=&wb;
           else           board[i][j]=&bb;
       }
    }
    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<'_';
    cout<<endl;
    for(i=0;i<8;i++){
        for(k=0;k<5;k++){
          cout<<" "<<char(179);
          for(j=0;j<8;j++){
             for(l=0;l<7;l++)
                cout<<(*board[i][j])[k][l];
          }
          cout<<char(179)<<endl;
        }
    }
    while(true){
      while(c<8){
         if(!from_backtrack) q[c]=-1;
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
      from_backtrack=true;
      backtrack(c);
     for(i=0;i<8;i++){
       if((i+q[i])%2==0) board[q[i]][i]=&wq;
       else              board[q[i]][i]=&bq;
    }
   }
    cout<<" ";
    for(i=0;i<8;i++)
       cout<<char(196);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
