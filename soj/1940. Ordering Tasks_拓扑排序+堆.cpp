#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100010;
int cases, n, m, a, b, in[MAX];
vector<int> out[MAX];

bool cmp(const int &x, const int &y)
{
     return x > y;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d", &cases );
    while (cases --)
    {
        vector<int> heap;
        scanf( "%d%d", &n, &m );
        for (int i = 1; i <= n; i ++)
        {
            in[i] = 0;
            out[i].clear();
        }
        while (m --)
        {
            scanf( "%d%d", &a, &b );
            in[b] ++;
            out[a].push_back(b);
        }
        for (int i = 1; i <= n; i ++)
            if (in[i] == 0)
            {
                heap.push_back(i);
                push_heap(heap.begin(), heap.end(), cmp);
            }
        
        for (int i = 1; i <= n; i ++)
        {
			int cur = heap[0]; 
			pop_heap(heap.begin(), heap.end(), cmp);
			heap.pop_back();

            printf( "%d ", cur );
            for (int j = 0; j < out[cur].size(); j ++)
            {
                in[ out[cur][j] ] --;
                if (in[ out[cur][j] ] == 0)
                {
                    heap.push_back(out[cur][j]);
                    push_heap(heap.begin(), heap.end(), cmp);    
                }
            }
        }  
        printf( "\n" );
    }
    
    return 0;
}
