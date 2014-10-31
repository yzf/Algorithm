#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int sum;
string str;

int getValue(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c-'A'+1;
	else
		return 0;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (getline(cin, str) && str[0] != '#')
	{
		sum = 0;
		for (int i = 0; i < str.length(); i ++)
			sum += (i+1) * getValue(str[i]);
		cout << sum << endl;
	}

    return 0;
}
