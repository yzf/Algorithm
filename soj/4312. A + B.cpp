#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[10];
int len;

void intToArray(int num) {
	memset(arr, 0, sizeof(arr));
	len = 0;
	while (num > 0) {
		arr[len ++] = num % 10;
		num /= 10;
	}
}

int arrayToInt() {
	int result = 0;
	int base = 1;
	for (int i = 0; i < len; i ++) {
		result += arr[i] * base;
		base *= 10;
	}
	return result;
}

int intReverse(int num) {
	intToArray(num);
	reverse(arr, arr + len);
	return arrayToInt();
}

int t;
int a, b;

int main() {
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	cin >> t;
	while (t --) {
		cin >> a >> b;
		cout << intReverse(a) + intReverse(b) << endl;
	}

	return 0;
}
