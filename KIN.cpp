//Shortest Path Problem - Part 1
//Written by Kin Zhao

#include<iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int cost(int i, int j){  //i is the row, j is the column
int weight[rows][cols] =
{{3,4,1,2,8,6},
{6,1,8,2,7,4},
{5,9,3,9,9,5},
{8,4,1,3,2,6},
{3,7,2,8,6,4},};

static int memo[rows][cols] =
{{3,0,0,0,0,0},
{6,0,0,0,0,0},
{5,0,0,0,0,0},
{8,0,0,0,0,0},
{3,0,0,0,0,0},};

int left, up, down;

//base case
if(j == 0)
return memo[i][0];

//recursive call
left = weight[i][j] + cost( i, j - 1);

if((i - 1) >= 0)
up = weight[i][j] + cost((i - 1) % rows, j - 1);
else
up = weight[i][j] + cost(rows - 1, j - 1);

if((i + 1) <= (rows - 1))
down = weight[i][j] + cost(i + 1, j - 1);
else
down = weight[i][j] + cost(0, j - 1);


//find the value of the shortest path through cell (i,j)
int min = up;

//some code goes here
if(left < min) min = left;
if(down < min) min = down;

memo[i][j] = min;
cout << memo[i][j];
if(memo[i][j] != 0)
return memo[i][j];
}

int main(){
int ex[rows];

//get the shortest path out of each cell on the right
for( int i = 0; i < rows; i++)
ex[i] = cost(i, cols - 1);

//now find the smallest of them
int min = ex[0];

//some code goes here
for(int i = 0; i < rows; i++)
if(ex[i] < min)
min = ex[i];

cout << "The shortest path of length is: " << min << endl << endl;

return 0;

}
