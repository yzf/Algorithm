#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n, b, x, y;
int a[100], c[100], d[100], lena, lenc, len;
int ans;

void nimSum()
{
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));

	int temp = x, i, j;
	lena = 0;
	while (temp > 0) {
		a[lena ++] = temp % b;
		temp /= b;
	}
	
	temp = y;
	lenc = 0;
	while (temp > 0) {
		c[lenc ++] = temp % b;
		temp /= b;
	}

	len = max(lena, lenc);
	for (i = 0; i < len; i ++) {
		d[i] = (a[i] + c[i]) % b;
	}
	
	ans = 0;	temp = 1;
	for (i = 0; i < len; i ++) {
		ans += d[i] * temp;
		temp *= b;
	}
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	cin >> t;
	while (t --) {
		cin >> n >> b >> x >> y;
		nimSum();
		cout << n << " " << ans << endl;
	}

	return 0;
}
