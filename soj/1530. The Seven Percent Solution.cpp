#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char str[100];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (gets(str) && str[0] != '#')
	{
		int len = strlen(str);
		for (int i = 0; i < len; i ++)
		{
			if (str[i] == ' ')
				printf( "%%20" );
			else if (str[i] == '!')
				printf( "%%21" );
			else if (str[i] == '$')
				printf( "%%24" );
			else if (str[i] == '%')
				printf( "%%25" );
			else if (str[i] == '(')
				printf( "%%28" );
			else if (str[i] == ')')
				printf( "%%29" );
			else if (str[i] == '*')
				printf( "%%2a" );
			else
				putchar(str[i]);
		}
		putchar( '\n' );
	}

    return 0;
}
