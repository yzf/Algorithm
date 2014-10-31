#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool num[10];
int n, digit, len, low, up;
char current[100];

bool isValid()
{
	if (current[0] == '0')	return false;
	for (int i = 0; i < len; i ++)
		if (!num[ current[i]-'0' ])	
			return false;
	return true;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		memset(num, false, sizeof(num));
		low = 10, up = -1;
		while (n --)
		{
			scanf( "%d", &digit );
			low = min(low, digit);
			up = max(up, digit);
			num[digit] = true;
		}
		scanf( "%s", current );
		len = strlen(current);
		if (!isValid())
		{
			puts("INVALID INPUT");
			continue;
		}

		bool flag = false;
		int i = len-1, j;
		while (i >= 0)
		{
			for (j = low; j <= up; j ++)
				if (num[j] && (j+'0') > current[i])
				{
					current[i] = j + '0';
					flag = true;
					break;
				}
			if (flag)	break;
			if (j == up+1)	current[i] = low + '0';
			i --;
		}
		if (!flag)
		{
			for (i = low; i <= up; i ++)
				if (i > 0 && num[i])
				{
					printf( "%c", i+'0' );
					break;
				}
		}
		for (i = 0; i < len; i ++)
			putchar(current[i]);
		printf( "\n" );
	}

	return 0;
}
