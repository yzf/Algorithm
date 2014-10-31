#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int p, q; 
vector<int> fp, fq;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d", &p, &q );
	for (int i = 1; i <= p; i ++)
		if (p % i == 0)
			fp.push_back(i);
	for (int i = 1; i <= q; i ++)
		if (q % i == 0)
			fq.push_back(i);

	for (int i = 0; i < fp.size(); i ++)
		for (int j = 0; j < fq.size(); j ++)
			printf( "%d %d\n", fp[i], fq[j] );

	return 0;
}
