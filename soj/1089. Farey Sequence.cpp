#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000;
bool isPrime[MAX+1];
int n, primeCount, prime[MAX+1];
long long euler[1000001], F[1000001];

void getPrime()
{
	primeCount = 0;
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= MAX; i ++)
	{
		if (isPrime[i])
			prime[primeCount ++] = i;
		for (int j = 0; j < primeCount && i*prime[j] <= MAX; j ++)
		{
			isPrime[i*prime[j]] = false;
			if (i%prime[j] == 0)
				break;
		}
	}
}

void getFareySequence()
{
	int p, j;
	for (int i = 2; i <= 1000000; i ++)
	{
		for (j = 0; j < primeCount; j ++)
			if (i%prime[j] == 0)
			{
				p = prime[j];
				break;
			}
		if (j == primeCount)
			euler[i] = i - 1;
		else if ((i/p)%p == 0)
			euler[i] = euler[i/p] * p;
		else
			euler[i] = euler[i/p] * (p - 1);
		
		F[i] = F[i-1] + euler[i];
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	getPrime();
	F[1] = 0;
	euler[1] = 1;
	getFareySequence();

	while (scanf( "%d", &n) && n != 0)
		printf( "%lld\n", F[n] );

    return 0;
}
