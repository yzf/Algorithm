#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//���ִ𰸣�Ȼ����֤��ǰ���Ƿ�Ϸ������ڵ�ǰ�𰸵�ȡ��ǰ�� , ����ȥ data[i] 
const int MAX = 1000;
int n, m;
int data[MAX];
int i, low, high, mid, ans;

bool isValid(int cn)
{
	int sum = 0;
	for (i = 0; i < n; i ++) {
		if (data[i] < cn) {
			sum += data[i];
		}
		else {
			sum += cn;
		}
	}
	if (m * cn <= sum) {
		return true;
	}
	return false;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n) {

		high = 0;
		for (i = 0; i < n; i ++) {
			scanf( "%d", &data[i] );
			high += data[i];
		}
		scanf( "%d", &m );

		low = 0;
		ans = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (isValid(mid)) {
				ans = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		printf( "%d\n", ans );
	}
	
	return 0;
}
