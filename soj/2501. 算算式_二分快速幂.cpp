#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//���ֿ�����
int n, k;
int s;
/*
mΪ������m&1==1��m=2k+1  A^(2k+1)=A^k * A^k *A  
mΪż����m&1==0��m=2k��A^2k= A^k * A^k 
*/
int myPow(int num, int x)
{
	if (x == 1) {
		return num;
	}
	int temp = myPow(num, x / 2) % 9901;
	if (x & 1) {
		return ((temp * temp) % 9901) * num  % 9901;
	}
	return temp * temp % 9901;
}
/*
S = A + A2 + A3 + �� + Am.
mΪ������m&1==1��m=2k+1�� S=A+A^2....A^k  + A^(2k+1)+   A^k (A+A^2....A^k  );
mΪż����m&1==0��m=2k�� S=A+A^2....A^k  +   A^k (A+A^2....A^k  );
*/
int sum(int x) 
{
	if (x == 1) {
		return n;
	}
	
	if (x & 1) {
		return ((((myPow(n, x / 2) + 1) * sum(x / 2)) % 9901) + myPow(n, x)) % 9901;
	}
	return (myPow(n, x / 2) + 1) * sum(x / 2) % 9901;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d", &n, &k ) != EOF) {
		if (k <= 0) {//����������ĵط�����������Գ�����������
			printf( "0\n" );
			continue;
		}
		s = sum(k) % 9901;
		printf( "%d\n", s );
	}
	
	return 0;
}
