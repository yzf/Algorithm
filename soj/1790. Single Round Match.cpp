#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cases, n, m, len1, len2, len, mo, s;
int man[1010], lady[1010], sum[1010];
char str[1010];

int add()
{
	memset(sum, 0, sizeof(sum));
	int l = max(len1, len2);
	for (int i = 0; i < l; i ++)
		sum[i] = man[i] + lady[i];//没把和变成正规的10进制数，因为这对后面的求商求余没影响
	return l;
}

void solve()
{
	mo = 0, s = 0;
	for (int i = len - 1; i >= 0; i --)
	{
		mo = mo * 10 + sum[i];
		if (mo < 11)
			continue;
		s = s * 10 + mo / 11;
		mo = mo % 11;
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		int i, j;
		scanf( "%s", str );
		len1 = strlen(str);
		for (i = len1-1, j = 0; i >= 0; i --)
			man[j ++] = str[i] - '0';

		scanf( "%s", str );
		len2 = strlen(str);
		for (i = len2-1, j = 0; i >= 0; i --)
			lady[j ++] = str[i] - '0';

		if (len1 != len2)
		{
			printf( "NO\n" );
			continue;
		}

		for (i = 0; i < len1; i ++)
			if (man[i] != lady[i])
				break;
		if (i != len1)
		{
			printf( "NO\n" );
			continue;
		}

		len = add();
		solve();
	
		if (mo != 0)
			printf( "NO\n" );
		else if (s % 2 != 0)
			printf( "NO\n" );
		else
			printf( "YES\n" );
	}

    return 0;
}
