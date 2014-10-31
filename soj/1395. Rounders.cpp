#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int t;
string number;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	cin >> t;
	while (t --)
	{
		cin >> number;
		int len = number.length();
		if (len > 1)
		{
			for (int i = len-1; i >= 1; i --)
			{
				if (number[i] > '4')
					number[i-1] ++;
				number[i] = '0';
			}
			if (number[0] > '9')
			{
				number[0] = '0';
				number = '1' + number;
			}
		}
		cout << number << endl;
	}

    return 0;
}
