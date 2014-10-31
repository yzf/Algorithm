#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 200;

int t, lena, lenb;
int revA[MAX], revB[MAX], answer[MAX];
char a[MAX], b[MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --)
	{
		scanf( "%s%s", a, b );

		memset(revA, 0, sizeof(revA));
		memset(revB, 0, sizeof(revB));
		memset(answer, 0, sizeof(answer));

		lena = strlen(a);
		lenb = strlen(b);

		int index = -1;
		for (int i = lena-1; i >= 0; i --)
			revA[++ index] = a[i] - '0';
		index = -1;
		for (int i = lenb-1; i >= 0; i --)
			revB[++ index] = b[i] - '0';
		
		index = 0;
		for (int i = 0; i < lenb; i ++)
		{
			for (int j = 0; j < lena; j++)
			{
				answer[index+j] += revA[j] * revB[i];
			}
			index ++;
		}

		for (int i = 0; i < MAX; i ++)
		{
			int temp = answer[i];
			answer[i] = temp % 10;
			answer[i+1] += temp / 10;
		}
		
		int be = -1;
		for (int i = MAX-1; i >= 0; i --)
			if (answer[i] != 0)
			{
				be = i;
				break;
			}
			
		if (be == -1)
		{
		    printf( "0\n" );
		    continue;
        }
		for (int i = be; i >= 0; i --)
			printf( "%d", answer[i] );
		printf( "\n");
	}

    return 0;
}
