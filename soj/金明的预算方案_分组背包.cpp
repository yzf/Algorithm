#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 70;
int n, m;
int v[MAX], p[MAX], q[MAX];
bool flag[32001];
int dp[32001];
int result;

struct Obj {
	int v, p;
} obj, obj2;
vector< vector<Obj> > objs;

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d%d", &n, &m );
	fprintf(stderr, "%d %d\n", n, m);
	for (int i = 1; i <= m; i ++) {
		scanf( "%d%d%d", &v[i], &p[i], &q[i] );
		fprintf(stderr, "%d %d %d\n", v[i], p[i], q[i]);
		vector<Obj> o;
		objs.push_back(o);
	}
	vector<Obj> o;
	objs.push_back(o);

	for (int i = 1; i <= m; i ++) {
		obj.v = v[i];
		obj.p = v[i] * p[i];
		if (q[i] == 0) 
			objs[i].push_back(obj);

		else {
			int cn = objs[ q[i] ].size();
			for (int j = 0; j < cn; j ++) {
				obj2.v = obj.v + objs[ q[i] ][j].v;
				obj2.p = obj.p + objs[ q[i] ][j].p;
				objs[ q[i] ].push_back(obj2);
			}
		}
	}

	flag[0] = true;
	for (int i = 0; i < objs.size(); i ++) {
		for (int j = n; j >= 0; j --)
			for (int k = 0; k < objs[i].size(); k ++) {
				int tmp = j - objs[i][k].v;
				if (tmp >= 0 && flag[tmp]) {
					flag[j] = true;
					dp[j] = max( dp[j], dp[tmp] + objs[i][k].p );
					result = max( result, dp[j] );
				}
			}
	}
	printf( "%d\n", result );

    return 0;
}                                 