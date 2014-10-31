#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int cases, n, m, mark;
string name;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		map<string, int> stu;
		scanf( "%d%d", &n, &m );
		while (n --)
		{
			cin >> name >> mark;
			stu[name] = mark;
		}
		while (m --)
		{
			cin >> name;
			if (stu[name] < 0 || stu[name] > 100)
				printf( "Score is error!\n" );
			else if (stu[name] < 60)
				printf( "E\n" );
			else if (stu[name] < 70)
				printf( "D\n" );
			else if (stu[name] < 80)
				printf( "C\n" );
			else if (stu[name] < 90)
				printf( "B\n" );
			else
				printf( "A\n" );
		}
	}

    return 0;
}
