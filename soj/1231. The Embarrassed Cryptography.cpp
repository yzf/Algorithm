#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000010;

char k[110];
int bigNum[35], l;
int ba[4] = {1, 10, 100, 1000};
int prime[MAX+1];
bool isPrime[MAX+1];

void getPrime()//线性筛选素数 
{
	memset(isPrime, true, sizeof(isPrime));
	int total = 0;
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

int module(int x)//求模 
{
	int mod = 0;
	for (int i = 34; i >= 0; i --)
		mod = (mod*ba[3] + bigNum[i]) % x;

	return mod;
}

void strToInt()//把字符串变成int 的数组，且是1000进制 
{
	memset(bigNum, 0, sizeof(bigNum));
	int len = strlen(k);
	int index = 0, base = 1;;
	for (int i = len -1, cn = 0; i >= 0; i --)
	{
		bigNum[index] += (k[i] - '0') * ba[cn];
		cn ++;
		if (cn == 3)
		{
			cn = 0;
			index ++;
		}
	}
}

int main()  
{  
    //freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	getPrime();
	for (scanf( "%s%d", k, &l ); l != 0; scanf( "%s%d", k, &l ))
	{
		strToInt();

		bool flag = true;
		int index = -1;
		for (int i = 0; prime[i] < l; i ++)
		{
			if (module(prime[i]) == 0)
			{
				flag = false;
				index = i;
				break;
			}
		}
		if (flag)
			printf( "GOOD\n" );
		else
			printf( "BAD %d\n", prime[index] );
	}

    return 0;  
}  
