#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 10000;

bool isPrime[MAX+1];
int n, primeNumber, prime[MAX+1], answer[MAX+1];

int getPrime()//ɸѡ�������������������� 
{
	int total = 0;
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= MAX; i ++)
	{
		if (isPrime[i])
			prime[total ++] = i;
		for (int j = 0; j < total && i*prime[j] <= MAX; j ++)
		{
			isPrime[i * prime[j]] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
	return total;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	memset(answer, 0, sizeof(answer));
    primeNumber = getPrime();

	int sum;
	for (int i = 0; i < primeNumber; i ++)//ͳ��10000���������ķַ� 
	{
		sum = 0;
		for (int j = i; j < primeNumber; j ++)
		{
			sum += prime[j];
			if (sum > MAX)
				break;
			answer[sum] ++;
		}
	}

	while (scanf("%d", &n ) && n > 0)
		printf( "%d\n", answer[n] );

    return 0;
}
