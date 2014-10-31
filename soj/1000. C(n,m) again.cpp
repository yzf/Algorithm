#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define int64 unsigned long long
int t;
int64 n, m, ans, temp, i, j; 
int a[10000], len;
bool flag[10000];

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &t );
	while (t --) {
		scanf( "%llu%llu", &n, &m );

		if (m > n / 2) {
			m = n - m;
		}
        //·Ö½â 2 ... m 
		len = 0;
		for (i = 2; i <= m; i ++) {
			temp = i;
			for (j = 2; j <= (int64)sqrt((double)i); j ++) {
				if (temp % j == 0) {
					a[len] = j;
					flag[len] = false;
					temp /= j;
					len ++;
				}
			}
			if (temp != 1) {
				a[len] = temp;
				flag[len] = false;
				len ++;
			}
		}
        //¼ÆËãC(n, m) 
		ans = 1;
		for (i = 0; i < m; i ++) {
			temp = n - i;
			for (j = 0; j < len; j ++) {
				if (!flag[j] && temp % a[j] == 0) {
					temp /= a[j];
					flag[j] = true;
				}
			}
			ans *= temp;
			for (j = 0; j < len; j ++) {
				if (!flag[j] && ans % a[j] == 0) {
					ans /= a[j];
					flag[j] = true;
				}
			}
		}

		printf( "%llu\n", ans );
	}

    return 0;  
} 
