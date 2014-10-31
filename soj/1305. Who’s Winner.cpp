#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;

bool doit() 
{
	int cn = 0;
	while (n > 9) {
		n = (cn & 1 ? ceil((double)n/9.0) : ceil((double)n/2.0));
		cn ++;
	}
	return (cn & 1 ? false : true);
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF) {
		if (doit()) {
			printf( "Nic wins.\n" );
		} 
		else {
			printf( "Susan wins.\n" );
		}
	}

    return 0;
}
/*
倒推出落如哪些区间是必胜的，哪些区间是必败的 
比如给定n=100，那么首先知道[12,99]是必胜区间（只要乘9） 
然后[6,11]是必败区间（无论乘多少必落入必胜区间）
一路倒推，求出p=1属于必胜区间还是比败区间
*/
