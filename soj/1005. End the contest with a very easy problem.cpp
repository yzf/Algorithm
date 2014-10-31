#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO = 10000000;
int t, n;
int data, a, b;

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	cin >> t;
	while (t --) {
		a = -OO;
		b = OO;
		cin >> n;
		while (n --) {
			cin >> data;
			a = max(a, data);
			b = min(b, data);
		}
		cout << a - b << endl;
	}

    return 0;  
} 
