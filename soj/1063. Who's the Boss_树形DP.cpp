#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 30010;
int cases, m, q, a;
struct Emp {
	int id, salary, height, son, father, brother;
	bool operator < (const Emp rhs) const {
		return salary < rhs.salary;
	}
} emp[MAX];
map<int, int> fa;
map<int, int> so;

void dfs(int fatherIndex)//求下属个数,以及对应上司 
{
	int sonIndex = emp[fatherIndex].son;
	fa[ emp[sonIndex].id ] = emp[fatherIndex].id;
	while (sonIndex != -1) {
		dfs(sonIndex);
		so[ emp[fatherIndex].id ] += so[ emp[sonIndex].id ] + 1;
		int temp = so[ emp[fatherIndex].id ];
		int temp2 = so[ emp[sonIndex].id ];
		sonIndex = emp[sonIndex].brother;
		fa[ emp[sonIndex].id ] = emp[fatherIndex].id;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --) {
		scanf( "%d%d", &m, &q );
		for (int i = 0; i < m; i ++) {
			scanf( "%d%d%d", &emp[i].id, &emp[i].salary, &emp[i].height );
			emp[i].father = emp[i].son = -1;
		}
        //建树 
		fa.clear();
		so.clear();
		sort(emp, emp+m);
		for (int i = 0; i < m - 1; i ++) {
			for (int j = i + 1; j < m; j ++) {
				if (emp[j].height >= emp[i].height) {
					emp[i].father = j;
					emp[i].brother = emp[j].son;
					emp[j].son = i;
					break;
				}
			}
		}
        //求下属个数,以及对应上司 
		dfs(m - 1);

		while (q --) {
			scanf( "%d", &a );
			printf( "%d %d\n", fa[a], so[a] );
		}
	}	

    return 0;
}
