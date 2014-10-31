#include <stdio.h>
#include <math.h>

long long n, num;

bool isPrime(int number)
{
	int i;
	for (i = 2; i <= (int)sqrt(number) + 1; i ++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	int p, i, ans = 0;
	scanf( "%lld", &n );
	for (p = 2; p <= n; p ++) {
		num = 1;
		for (i = 1; i <= p; i ++) {
			num <<= 1;
		}
		num --;
		if (isPrime(num)) {
			ans ++;
		}
	}
	printf( "%d\n", ans );

	return 0;
}
