#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int a, b, c, d;
int up, down;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	cin >> t;
	while (t --) {
		cin >> a >> b >> c >> d;
		down = lcm(b, d);
		a = a * (down / b);
		c = c * (down / d);
		up = a + c;
		int tmp = gcd(up, down);
		up /= tmp;
		down /= tmp;
		if (down == 1)
			cout << up << endl;
		else 
			cout << up << "/" << down << endl;
	}

    return 0;
}                                 