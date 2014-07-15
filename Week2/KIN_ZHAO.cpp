// Eight Numbers in a Cross
// Written by Kin Zhao
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[8], int c){
int a[][5] =
{{-1},
{0, -1},
{1, -1},
{2, 1, 0, -1},
{1, 2, 3, -1},
{0, 3, 4, -1},
{3, 4, 5, -1},
{2, 4, 6, -1},};

//row test
for( int i = 0; i < c; ++i)
if (q[i] == q[c])
return false;
//diagonal test
for( int i = 0; a[c][i] != -1; ++i) {
if( 1 == abs( q[c] - q[ a[c][i] ]))
return false;
}
return true;
}

void backtrack(int &col){
--col;
}

void print(int q[]){
static int count = 0;
cout << "Solution # " << ++count << endl << endl;
cout << "  " << q[1] << " " << q[2] << "  " << endl;
cout << q[0] << " " << q[3] << " " << q[4] << " " << q[7] << endl;
cout << "  " << q[5] << " " << q[6] << endl;
}


int main() {
int x=0;
int q[8] = {0}, c = 0;
bool frombacktrack = false;

while(true){
while(c < 8){
if(frombacktrack = false)
q[c] = -1;

frombacktrack = false;

while(q[c] < 8){
q[c]++;

if(q[c] == 8){
backtrack (c);
continue;
}

if(ok(q, c))
break;
}
c++;
}
print(q);
cin >> x;
backtrack(c);
frombacktrack = true;
}
}
