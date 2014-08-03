//Shortest Path -Part 2
//Written by Kin Zhao

#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

const int weight[rows][cols] =
	{{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}};

struct info{
	int weight;
	int path;
	info(){
	weight = 0;
	path = 0;
	}
};

info memo[rows][cols];

//global path array- find path
int path[rows][cols] = {0};

int main(){
	//setup the base case
	for( int r = 0 ; r < rows ; ++r )
	memo[r][0].weight = weight[r][0];

	//for every column go through each row to figure out the weight
	for( int c = 1 ; c < cols ; ++c ){
	for( int r = 0 ; r < rows ; ++r ){

	int left, up, down;

	//figure out the cost of up and down
	left = memo[r][c-1].weight;
	up = memo[r-1][c-1].weight;
	down = memo[r+1][c-1].weight;

	int min = up;
	memo[r][c].path = -1;

	if( left < min ){
	min = left;
	memo[r][c].path = 0;
	}

	if( down < min ){
	min = down;
	memo[r][c].path = 1;
	}

	memo[r][c].weight = min + weight[r][c];
	cout << "The shortest path of length is: " << min << endl << endl;
	}
	}

	for( int i = 0 ; i < rows ; ++i ){
	cout << memo[i][0].weight << " " << memo[i][0].path << "\t"
	<< memo[i][1].weight << " " << memo[i][1].path << "\t"
	<< memo[i][2].weight << " " << memo[i][2].path << "\t"
	<< memo[i][3].weight << " " << memo[i][3].path << "\t"
	<< memo[i][4].weight << " " << memo[i][4].path << "\t"
	<< memo[i][5].weight << " " << memo[i][5].path <<"\n";
	}

	//cout << "The shortest path of length is: " << min << endl << endl;
	//print out the steps to travel through the source code
	return 0;
}
