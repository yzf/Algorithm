#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int a, b, low, high;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> t;
	while (t --)
	{
		cin >> a >> b >> low >> high;
		bool flag = false;
		for (int i = high; i >= low; i --)
		{
			if (a % i == 0 && b % i == 0)
			{
				flag = true;
				printf("%d\n", i);
				break;
			}
		}
		if (!flag)
		{
			puts("No answer");
		}
	}

    return 0;
}
