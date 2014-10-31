#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string str;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	while (cin >> str && str != "XXX")
	{
		int len = str.length();
		str.append("a");
		for (int i = 0; i < len;)
		{
			int cn, k, j;

			cn = 0; k = 1;
			for (; k+i <= len; k ++)
			{
				if (str[k+i] >= 'a' && str[k+i] <= 'z')
					break;
				cn = cn * 10 + str[k+i] - '0';
			}
			if (cn == 0)
				printf( "%c", str[i] );
			for (j = 0; j < cn; j ++)
				printf( "%c", str[i] );

			i += k;
		}
		printf( "\n" );
	}

	return 0;
}
