#include <iostream>
using namespace std;

void move(char from, char to, char extra, int n){
	static int call=0;
	//cout << call++ << " ";
	if(n==1){
		cout << call++ << ": ";
		cout << "Move ring from " << from << " to " << to << endl;
		return;
	}
	move(from, extra, to, n-1);
	cout << call++ << ": ";
	cout << "Move ring from " << from << " to " << extra << endl;
	move(extra, to, from, n-1);
	return;
}

int main(){
	move('A', 'B', 'C', 10);
	return 0;
}
