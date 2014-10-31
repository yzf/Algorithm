#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n, m, num, apple;
int l, r, result;

int main() {
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> t;
	while (t --) {
		cin >> n >> m >> num;
		l = 1;
		r = l + m - 1;
		result = 0;
		for (int i = 0; i < num; i ++) {
			cin >> apple;
			if (apple < l) {
				int tmp = l - apple;
				l -= tmp;
				r -= tmp;
				result += tmp;
			}
			else if (apple > r) {
				int tmp = apple - r;
				r += tmp;
				l += tmp;
				result += tmp;
			}
		}
		cout << result << endl;
	}

    return 0;
}
