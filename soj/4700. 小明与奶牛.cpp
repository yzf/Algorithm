#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n;
int a, b;
int r1, r2, r3;

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    cin >> t;
	while (t --) {
		cin >> n;
		r1 = r2 = r3 = -1;
		for (int i = 0; i < n; i ++) {
			cin >> a >> b;
			switch (a) {
				case 1:
					r1 = max(r1, b);
					break;
				case 2:
					r2 = max(r2, b);
					break;
				case 3:
					r3 = max(r3, b);
					break;
			}
		}
		if (r1 != -1) 
			cout << 1 << " " << r1 << endl;
		if (r2 != -1) 
			cout << 2 << " " << r2 << endl;
		if (r3 != -1)
			cout << 3 << " " << r3 << endl;
	}

    return 0;
}                                 