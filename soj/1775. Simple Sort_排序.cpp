#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, m, q;

struct Priority {
	int pri;
	int col;
	bool operator < (const Priority rhs) const {
		return pri < rhs.pri;
	}
} priority[20];

struct Data {
	int num[20];
	int id;
	bool operator < (const Data rhs) const {
		for (int i = 0; i < m; i ++) {
			int col = priority[i].col;
			if (num[col] != rhs.num[col])	
				return num[col] < rhs.num[col];
		}
		return false;//return true;¾ÍWA¡£¡£¡£
	}
} data[200];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --) {

		scanf( "%d%d", &n, &m );
		for (int i = 0; i < n; i ++) {
			data[i].id = i;
			for (int j = 0; j < m; j ++)
				scanf( "%d", &data[i].num[j] );
		}

		scanf( "%d", &q );
		while (q --) {
			for (int i = 0; i < m; i ++) {
				priority[i].col = i;
				scanf( "%d", &priority[i].pri );
			}

			stable_sort(priority, priority+m);
			stable_sort(data, data+n);
			
			printf( "%d", data[0].id );
			for (int i = 1; i < n; i ++)
				printf( " %d", data[i].id );
			printf( "\n" );
		}
	}

	return 0;
}
