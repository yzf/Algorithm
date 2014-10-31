#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 25000;
int n;
struct Toy {
	double j, p, h;
	int id;
} toy[MAX];

bool cmp(const Toy &a, const Toy &b)
{
	return a.h > b.h;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	for (int i = 0; i < n; i ++)
	{
		scanf( "%lf%lf", &toy[i].j, &toy[i].p );
		toy[i].h = toy[i].j / toy[i].p;
		toy[i].id = i + 1;
	}
	sort(toy, toy+n, cmp);
	printf( "%.lf\n", toy[0].p+toy[1].p+toy[2].p );
	for (int i = 0; i < 3; i ++)
		printf( "%d\n", toy[i].id );

	return 0;
}
