#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 200001;
int n, m, data[MAX];
int l, r, cn[MAX], answer, sum;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d", &n, &m );
	for (int i = 0; i < n; i ++)
		scanf( "%d", &data[i] );

	memset(cn, 0, (m+1)*sizeof(int));
	l = r = 0;		cn[ data[0] ] = 1;
	sum = 1;		answer = n+1;
	while (r < n)
	{
		while (sum < m)
		{
			r ++;
			if (cn[ data[r] ] == 0)
				sum ++;
			cn[ data[r] ] ++;
		}
		if (r - l + 1 < answer)		answer = r - l + 1;
		if (cn[ data[l] ] == 1)		sum --;
		cn[ data[l] ] --;
		l ++;
	}
	if (answer < n+1)
		printf( "%d\n", answer );
	else
		printf( "NO\n" );
 
	return 0;
}

