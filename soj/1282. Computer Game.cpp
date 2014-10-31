#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 60000;
int n1, n2, ne[MAX+1];
int a[MAX+1], b[MAX*50+1];
int answer;

void getNext()
{
	int i = 1, j = 0;
	while (i <= n1)
	{
		if (j == 0 || a[i] == a[j])
		{
			i ++;	j ++;
			ne[i] = j;
		}
		else
			j = ne[j];
	}
}

int KMP()
{
	int i = 1, j = 1;
	while (i <= n2 && j <= n1)
	{
		if (j == 0 || a[j] == b[i])
		{
			i ++;	 j ++;
		}
		else
			j = ne[j];
	}
	if (j > n1)
		return i-n1-1;
	else
		return -1;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n1 ) != EOF)
	{
		for (int i = 1; i <= n1; i ++)
			scanf( "%d", &a[i] );

		scanf( "%d", &n2 );
		for (int i = 1; i <= n2; i ++)
			scanf( "%d", &b[i] );

		getNext();
		answer = KMP();
		if (answer >= 0)
			printf( "%d\n", answer );
		else
			printf( "no solution\n" );
	}

	return 0;
}
