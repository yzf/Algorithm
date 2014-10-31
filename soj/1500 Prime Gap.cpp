#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1299800;

int n, answer;
int prime[MAX+1];
bool isPrime[MAX+1];

void getPrimeList()
{
	int total = 0;
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= MAX; i ++)
	{
		if (isPrime[i])
			prime[total ++] = i;
		for (int j = 0; j < total && i*prime[j] <= MAX; j ++)
		{
			isPrime[i*prime[j]] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	getPrimeList();
	while (scanf("%d", &n) && n != 0)
	{
		answer = 0;
		if (isPrime[n])
			printf( "0\n" );
		else
		{
			int upBound, lowBound;
			upBound = lowBound = n;
			while (true)
			{
				upBound ++;
				if (isPrime[upBound])
					break;
			}
			while (true)
			{
				lowBound --;
				if (isPrime[lowBound])
					break;
			}
			printf( "%d\n", upBound - lowBound );
		}
	}

    return 0;
}
