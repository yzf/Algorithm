#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

bool isRead[110];
int n, m, a, b, ans, father[110];

struct Book {
    int id;
    int cost;
    bool operator < (const Book &rhs) const 
    {
        return cost < rhs.cost;
    }
} book[110];

void make_set()
{
    for (int i = 0; i < n; i ++)
        father[i] = i;
}

int find_set(int &x)
{
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

void union_set(int &x, int &y)
{
    int fx = find_set(x);
    int fy = find_set(y);
    father[fy] = fx;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    while (scanf( "%d%d", &n, &m ) && n != 0 && m != 0)
    {
        memset(isRead, false, sizeof(isRead));
        make_set();
        for (int i = 0; i < n; i ++)
        {
            scanf( "%d", &book[i].cost );
            book[i].id = i;
        }
        while (m --)
        {
            scanf( "%d%d", &a, &b );
            union_set(a, b);
        }
        sort(book, book+n);
        ans = 0;
        for (int i = 0; i < n; i ++)
        {
            if (isRead[ find_set(book[i].id) ])
                ans += book[i].cost / 2;
            else
                ans += book[i].cost;
            isRead[ find_set(book[i].id) ] = true;
        }
        printf( "%d\n", ans );
    }

    return 0;
}
