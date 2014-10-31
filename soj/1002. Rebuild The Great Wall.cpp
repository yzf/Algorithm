#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 10000000;
const int MAX = 100010;
int n, t, ans;
int data[MAX], sum[MAX], que[MAX], id[MAX], len;
//先求出0~i的部分和，维护部分和的单调队列并保证队尾-队头不超过T 
int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d%d", &n, &t ) != EOF) {

		sum[0] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf( "%d", &data[i] );
			sum[i] = sum[i - 1] + data[i];
		}

		ans = oo;
		len = 0;
		for (int i = 1; i <= n; i ++) {

			if (sum[i] > t) {
				ans = min(ans, i);
			}
			while (len > 0 && sum[i] <= que[len - 1]) {
				len --;
			}

			int l = 0, r = len - 1;
			int mid = (l + r) / 2;
			if (l == r) {
				if (sum[i] - que[mid] > t) {
					ans = min(ans, i - id[mid]);
					l = mid + 1;
				}
			}
			else {
				while (l < r) {
					if (sum[i] - que[mid] > t) {
						ans = min(ans, i - id[mid]);
						l = mid + 1;
					}
					else {
						r = mid;
					}
					mid = (l + r) / 2;
				}
			}

			que[len] = sum[i];
			id[len] = i;
			len ++;
		}

		printf( "%d\n", ans );
	}

    return 0;  
} 
