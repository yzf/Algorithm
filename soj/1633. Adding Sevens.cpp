#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <bitset>
#include <map>

using namespace std;

int a, b;
string str;
string num[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};
map<string, int> aa;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	for (int i = 0; i < 10; i ++)
		aa[ num[i] ] = i;

	while (cin >> str && str[0] != 'B')
	{
		int plus = str.find_first_of('+');
		int equ = str.find_first_of('=');

		a = b = 0;
		for (int i = 0; i < plus; i += 3)
			a = a * 10 + aa[ str.substr(i, 3) ];
		for (int i = plus+1; i < equ; i += 3)
			b = b * 10 + aa[ str.substr(i, 3) ];

		int digit[20];
		int temp = a + b, len = 0;
		while (temp > 0)
		{
			digit[len ++] = temp % 10;
			temp /= 10;
		}

		for (int i = len-1; i >= 0; i --)
			str += num[ digit[i] ];

		cout << str << endl;
	}
		
    return 0;
}
