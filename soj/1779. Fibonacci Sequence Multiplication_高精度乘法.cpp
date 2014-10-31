#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int cases, a, b, n, resultTemp[1010];
char c[20];
bool flag;
string m1, m2, temp;

bool mul()
{
	int i, j;
	string result, temp = m2;
	memset(resultTemp, 0, sizeof(resultTemp));
	int len1 = m1.length(), len2 = m2.length(), len = len1 + len2 + 1;
	if (len > 1010)	{//估计长度比1010长时，返回
		return false;
	}
	//高精度乘法
	reverse(m1.begin(), m1.end());
	reverse(m2.begin(), m2.end());
	for (i = 0; i < len1; i ++) {
		for (j = 0; j < len2; j ++) {
			resultTemp[i+j] += (m1[i] - '0') * (m2[j] - '0');
		}
	}
	for (i = 0; i < len; i ++) {
		resultTemp[i+1] += resultTemp[i] / 10;
		resultTemp[i] %= 10;
	}
	if (resultTemp[len] != 0) {
		len ++;
	}

	for (i = len-1; i >= 0; i --) {
		if (resultTemp[i] > 0) {
			break;
		}
	}
	if (i+1 > 1000)		return false;//实际结果长度大于1000时，返回
	for (; i >= 0; i --) {
		result.push_back(resultTemp[i] + '0');
	}
	m1 = temp;
	m2 = result;
	return true;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --) {
		scanf( "%d%d%d", &a, &b, &n );

		if (n == 1) {
			printf( "%d\n", a );
			continue;
		}
		if (n == 2) {
			printf( "%d\n", b );
			continue;
		}
		if (a == 1 && b == 1) {
			printf( "1\n" );
			continue;
		}
		if (n >= 21) {//对于a=1,b=2，n=21时已经超过1000位
			printf( "Ooops!\n" );
			continue;
		}

		sprintf(c, "%d", a);
		m1 = string(c);
		sprintf(c, "%d", b);
		m2 = string(c);
		flag = true;
		for (int i = 3; i <= n; i ++) {
			if(!mul()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << m2 << endl;
		}
		else {
			printf( "Ooops!\n" );
		}
	}

    return 0;
}
