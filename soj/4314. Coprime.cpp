#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a,int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	int t, a, b;
	cin >> t;
	while (t --) {
		cin >> a >> b;
		if (gcd(a, b) == 1) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}

	return 0;
}
