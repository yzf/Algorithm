#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int key;
int a[10001];

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	memset(a, -1, sizeof(a));

	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> key;
		int id = key % m;
		
		for (int j = id; ; j = (j + 1) % m) {
			if (a[j] == -1) {
				a[j] = key;
				break;
			}
		}
	}

	for (int i = 0; i < m; i ++) {
		cout << i << "#";
		if (a[i] != -1)
			cout << a[i] << endl;
		else 
			cout << "NULL" << endl;
	}

    return 0;
}                                 