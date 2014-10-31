#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool flag;
int len1, len2, num;
char str[100], ans[100];

int main() 
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (gets(str))
	{
		flag = true;
		num = 0;
		len1 = strlen(str);
		len2 = 0;
		for (int i = 0; i < len1; i ++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (num == 0)
				{
					ans[len2 ++] = str[i];
					if (len2 > 50)
					{
						flag = false;			
						break;
					}
				}
				for (int j = 0; j < num; j ++)
				{
					ans[len2 ++] = str[i];
					if (len2 > 50)
					{
						flag = false;			
						break;
					}
				}
				if (!flag)
					break;
				num = 0;
			}
			else
			{
				num = num * 10 + str[i] - '0';
				if (num > 50)
				{
					flag = false;			
					break;
				}
			}
		}

		if (!flag)
		{
			printf( "TOO LONG\n" );
			continue;
		}

		ans[len2] = '\0';
		printf( "%s\n", ans );
	}
	    
	return 0;
}
/*
1、可能前面50个字符都是数字，要判断是否超出了输出是否超过50个字符
2、有可能输入空行
*/
