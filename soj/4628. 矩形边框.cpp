#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int  t, row, col;

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	cin >> t;
	while (t --) {
		cin >> col >> row;
		for (int i = 0; i < col; i ++) 
			cout << "*";
		cout << endl;
		for (int i = 1; i < row - 1; i ++) {
			cout << "*";
			for (int j = 1; j < col - 1; j ++) 
				cout << " ";
			cout << "*" << endl;
		}
		for (int i = 0; i < col; i ++) 
			cout << "*";
		cout << endl << endl;;
	}

    return 0;
}                                 