#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long prime[30];
int k, len;
int mersenne[9] = {11, 23, 29, 37, 41, 43, 47, 53, 59}; 

void doit(int exp)
{
	long long ans = 1, temp, sqrtOfTemp, factor1, factor2;
	len = 0;

	for (int i = 0; i < exp; i ++) {
		ans <<= 1;
	}
	ans --;

	temp = ans;
	while (temp % 3 == 0) {//不可能被2整除
		prime[len ++] = 3;
		temp /= 3;
	} 
	sqrtOfTemp = (long long)sqrt((double)temp);
	for (int i = 1; ; i ++) {
		factor1 = i * 6 - 1;
		factor2 = i * 6 + 1;
		while (temp % factor1 == 0) {
			prime[len ++] = factor1;
			temp /= factor1;
			sqrtOfTemp = (long long)sqrt((double)temp);
		}
		while (temp % factor2 == 0) {
			prime[len ++] = factor2;
			temp /= factor2;
			sqrtOfTemp = (long long)sqrt((double)temp);
		}
		if (factor1 >= sqrtOfTemp) {
			prime[len ++] = temp;
			break;
		}
	}

	printf( "%lld", prime[0] );
	for (int i = 1; i < len; i ++) {
		printf( " * %lld", prime[i] );
	}
	printf( " = %lld = ( 2 ^ %d ) - 1\n", ans, exp );
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &k );
	for (int i = 0; mersenne[i] <= k && i < 9; i ++) {
		doit(mersenne[i]);
	}

    return 0;
}
