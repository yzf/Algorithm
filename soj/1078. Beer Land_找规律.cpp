#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n;
/*
����������Ҫk����ʹ��k������ͨ�ұ�֤�ж�����һ���ߺ���Ȼ��ͨ�����ӷ���ֻ��һ�������һ������ 
��������ʱ��ÿ���������k-3���߽��棬���Խ���������k*(k-3)/2 
ż������ʱ����2���ߵĽ��������������Ķ�1����ʱ������������ǣ�( (k-3)*2+(k-4)*(k-2) )/2 
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
