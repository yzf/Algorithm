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
���Ƴ�������Щ�����Ǳ�ʤ�ģ���Щ�����Ǳذܵ� 
�������n=100����ô����֪��[12,99]�Ǳ�ʤ���䣨ֻҪ��9�� 
Ȼ��[6,11]�Ǳذ����䣨���۳˶��ٱ������ʤ���䣩
һ·���ƣ����p=1���ڱ�ʤ���仹�ǱȰ�����
*/
