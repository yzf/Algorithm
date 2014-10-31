#include <iostream>
#include <cstdio>  
#include <queue>  

using namespace std;  
  
const int MAX = 32769;
int n, l, u, ans;
struct Sum {
	int s, pos;
	bool operator < (const Sum &rhs) const 
	{
		return s < rhs.s;
	}
} sum[MAX], temp;
  
int main()  
{  
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    while (scanf( "%d", &n ) && n != 0)
	{
		priority_queue<Sum> que;

		scanf( "%d%d", &l, &u );
		sum[0].s = 0;	sum[0].pos = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf( "%d", &sum[i].s );
			sum[i].s += sum[i-1].s;
			sum[i].pos = i;
		}
		que.push(sum[0]);
		ans = 1 << 30;
		for (int i = l; i <= n; i ++)
		{
			while (true)
			{
				temp = que.top();
				if (i-temp.pos >= l && i-temp.pos <= u)
					break;
				que.pop();
			}
			ans = min(ans, sum[i].s-sum[temp.pos].s);
			que.push(sum[i-l+1]);
		}
		printf( "%d\n", ans );
	}
  
    return 0;  
}  
