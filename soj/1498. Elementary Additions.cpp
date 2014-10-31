#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n, ans;
string num[16], num1, num2;
map<string, int> numMap;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	num[0] = "{}";
	numMap[ num[0] ] = 0;
	for (int i = 1; i < 16; i ++)
	{
		num[i] += '{';
		for (int j = 0; j < i-1; j ++)
		{
			num[i] += num[j];
			num[i] += ',';
		}
		num[i] += num[i-1];
		num[i] += '}';
		numMap[ num[i] ] = i;
	}
	cin >> n;
	while (n --)
	{
		cin >> num1 >> num2;
		ans = numMap[ num1 ] + numMap[ num2 ];
		cout << num[ ans ] << endl;
	}

    return 0;
}
