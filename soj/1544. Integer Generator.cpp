#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool ok, flag[10];
char str1[15], str2[15];

bool check(char *num)
{
	int len = strlen(num);
	if (num[0] == '0')
		return false;
	for (int i = 0; i < len; i ++)
		if (!flag[ num[i]-'0' ])
			return false;
	return true;
}

void init()
{
	memset(flag, false, sizeof(flag));
	int len = strlen(str1);
	for (int i = 0; i < len; i ++)
		flag[ str1[i]-'0' ] = true;
}

int main()
{  
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
   
	while (scanf( "%s%s", str1, str2 ) != EOF)
	{
		init();
		if (!check(str2))
		{
			printf( "INVALID INPUT\n" );
			continue;
		}

		int i, be;
		for (i = 0; i < 10; i ++)
			if(flag[i])
			{
				be = i;
				break;
			}

		ok = false;
		int len = strlen(str2);
		int cur = len-1;
		while (cur >= 0)
		{
			for (i = 0; i < 10; i ++)
			{
				if (flag[i] && str2[cur]-'0' < i)
				{
					str2[cur] = i + '0';
					ok = true;
					break;
				}
			}
			if (i == 10)
			{
				str2[cur] = be + '0';
				cur --;
			}

			if (ok)
				break;
		}
		
		if (ok)
			printf( "%s\n", str2 );
		else
		{
			for (int i = 1; i < 10; i ++)
				if (flag[i])
				{
					printf( "%d", i );
					break;
				}
			printf( "%s\n", str2 );
		}
	}

    return 0;  
}  
