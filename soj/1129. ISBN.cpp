#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int sum, a[9];
string isbn;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (cin >> isbn)
	{
		sum = 0;
		int index = -1;
		for (int i = 0; i < isbn.length(); i ++)
			if (isbn[i] != '-')
				a[++ index] = isbn[i] - '0'; 

		for (int i = 0; i < 9; i ++)
			sum += a[i] * (10-i);

		sum %= 11;
		isbn.push_back('-');
		if (sum == 0)
			isbn.push_back(sum+'0');
		else if (sum == 1)
			isbn.push_back('X');
		else
			isbn.push_back(11-sum+'0');
		cout << isbn << endl;
	}
	
	return 0;
}
