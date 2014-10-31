#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int cases, n, m, c, p, s, pro;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --) {
		scanf( "%d%d%d%d%d", &n, &m, &c, &p, &s );
		int t = (int)ceil((double)p / (double)c);
		if (s < t) {
			m += n * c * s;
		}
		else {
			pro = m / p;
			n += pro;
			m -= pro * p;
			for (int i = 1; i <= s - t; i ++) {
				m += n * c;
				pro = m / p;
				n += pro;
				m -= pro * p;
			}
			m += n * c * t;
		}
		printf( "%d\n", m );
	}

    return 0;
}
