#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n;
/*
首先最少需要k个边使得k个点连通且保证切断任意一条边后仍然连通。连接方法只有一种情况：一个环。 
奇数个点时，每条边最多与k-3个边交叉，所以交叉点最多是k*(k-3)/2 
偶数个点时，有2条边的交点数量比其他的多1，此时交点数量最大。是：( (k-3)*2+(k-4)*(k-2) )/2 
*/
int main()  
{  
    //freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	while (cases --) {
		scanf( "%lld", &n );
		if (n < 3) {
			printf( "0\n" );
		}
		else if (n & 1) {
			printf( "%d\n", n*(n - 3)/2 );
		}
		else {
			printf( "%d\n", ((n - 3)*2 + (n - 4)*(n - 2)) / 2 );
		}
	}

    return 0;  
} 
