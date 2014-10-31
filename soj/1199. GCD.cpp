#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 33333;
double ans;
int cases, n, m, primeCount, difPrime, prime[MAX+1];
bool isPrime[MAX+1];

struct {
	int pri;
	int cn;
} resolve[50];

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
			isPrime[ i*prime[j] ] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
}

void factorization()
{
	int cnt = 0, tempN = n;
	difPrime = 0;
	for (int i = 0; prime[i]*prime[i] <= tempN && i < primeCount; i ++)
	{
		while (tempN % prime[i] == 0)
		{
			cnt ++;
			tempN /= prime[i];
		}
		if (cnt)
		{
			resolve[difPrime].cn = cnt;
			resolve[difPrime].pri = prime[i];
			difPrime ++;
			cnt = 0;
		}
	}
	if (tempN != 1)
	{
		resolve[difPrime].cn = 1;
		resolve[difPrime ++].pri = tempN;
	}
}

void dfs(int be, double pro, double tot)
{
	double tempPro = pro, tempTot = tot;

	if (be == difPrime)
	{
		if ((double)n/pro >= m)
			ans += pro * tot;

		return ;
	}

	for (int i = 0; i <= resolve[be].cn; i ++)
	{
		for (int j = 1; j <= i; j ++)
			pro *= resolve[be].pri;

		if (i > 0)
			tot *= (1.0 - 1.0/(double)resolve[be].pri);

		dfs(be+1, pro, tot);

		//×´Ì¬»¹Ô­
		pro = tempPro;
		tot = tempTot;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	getPrime();

	scanf( "%d", &cases );
	while (cases --)
	{
		ans = 0.0;
		memset(resolve, 0, sizeof(resolve));
		scanf( "%d%d", &n, &m );
		
		if (m == 1)
			ans = n;
		else
		{
			factorization();
			dfs(0, 1.0, 1.0);
		}
		printf ( "%.0lf\n" , ans ) ;
	}

    return 0 ;
}
