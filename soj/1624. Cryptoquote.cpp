#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases;
char encoded[1000], key[30];
char decoded[1000];

char decode(char k)
{
	int index = k - 'A';
	return key[index];
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	getchar();
	for (int caseNum = 1; caseNum <= cases; caseNum ++)
	{
		gets(encoded);
		gets(key);

		int len = strlen(encoded);
		for (int i = 0; i < len; i ++)
		{
			if (encoded[i] >= 'A' && encoded[i] <= 'Z')
				decoded[i] = decode(encoded[i]);
			else
				decoded[i] = encoded[i];
		}
		decoded[len] = '\0';

		printf( "%d %s\n", caseNum, decoded );
	}
   
    return 0;
}
