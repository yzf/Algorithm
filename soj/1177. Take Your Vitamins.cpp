#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

double a, r, per;
string u, v;
queue<string> q;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (cin >> a && a >= 0)
	{
		cin >> u >> r;
		cin.get();
		getline(cin, v);

		per = a / r * 100;
		if (per < 1.0)
		{
			q.push(v);
			continue;
		}

		printf( "%s %.1lf %s %.0lf", v.c_str(), a, u.c_str(), per );
		puts( "%" );
	}
	printf( "Provides no significant amount of:\n" );
	while (!q.empty())
	{
		printf( "%s\n", q.front().c_str() );
		q.pop();
	}

    return 0;
}
