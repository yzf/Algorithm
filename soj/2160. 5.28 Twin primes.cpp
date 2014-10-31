#include <stdio.h>
#include <string.h>

const int MAX = 100000;
bool isPrime[MAX + 1];
int tot, prime[MAX + 1];
int n, ans[MAX + 1];

void getPrime()
{
	int i, j;
	tot = 0;
	memset(isPrime, true, sizeof(isPrime));
	for (i = 2; i < MAX; i ++) {
		if (isPrime[i]) {
			prime[tot ++] = i;
		}
		for (j = 0; j < tot && i*prime[j] < MAX; j ++) {
			isPrime[i * prime[j]] = false;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	getPrime();
	int i, j;
	for (i = 6; i <= MAX; i++) {
		ans[i] = ans[i - 1];
		if (isPrime[i - 1] && isPrime[i - 3]) {
			ans[i] ++;
		}
	}

	while (scanf( "%d", &n ) != EOF) {
		printf( "%d\n", ans[n] );
	}

	return 0;
}
