#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[110], isRead[110];
int n, m, a, b, ans;
struct Book {
    int time;
    int num;
} book[110];

bool cmp(const Book &a, const Book &b)
{
    return a.time < b.time;
}

bool bfs(vector<int> adjacent[], int &bookNum)
{
    memset(visited, false, sizeof(visited));
    queue<int> bookQue;
    int temp, ne;
    
    bookQue.push(bookNum);
    visited[bookNum] = true;
    while (!bookQue.empty())
    {
        temp = bookQue.front();
        bookQue.pop();
        
        for (int i = 0; i < adjacent[temp].size(); i ++)
        {
            ne = adjacent[temp][i];
            if (!visited[ne])
            {
                bookQue.push(ne);
                visited[ne] = true;
                if (isRead[ne])    return true;
            }
        }
    }
    return false;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    while (scanf( "%d%d", &n, &m ) && n != 0 && m != 0)
    {
        memset(isRead, false, sizeof(isRead));
        vector<int> adjacent[110];
        
        for (int i = 0; i < n; i ++)
        {
            scanf( "%d", &book[i].time );
            book[i].num = i;
        }
            
        while (m --)
        {
            scanf( "%d%d", &a, &b );
            adjacent[a].push_back(b);
            adjacent[b].push_back(a);
        }
        
        sort(book, book+n, cmp);
        ans = 0;
        for (int i = 0; i < n; i ++)
        {
            if (bfs(adjacent, book[i].num))
                ans += book[i].time / 2;
            else
                ans += book[i].time;
            isRead[book[i].num] = true;
        }
        printf( "%d\n", ans );
    }
    
    return 0;
}
