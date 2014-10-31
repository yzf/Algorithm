#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 50;

bool flag[MAX][MAX];
bool visited[MAX][MAX];
int w, h;
int n;
int count;
int dir_h[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dir_w[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int cur_h, int cur_w) {
    visited[cur_h][cur_w] = true;
    for (int i = 0; i < 8; ++ i) {
        int next_h = cur_h + dir_h[i];
        int next_w = cur_w + dir_w[i];
        if (next_h >= 0 && next_h < h
                && next_w >= 0 && next_w < w
                && flag[next_h][next_w]
                && ! visited[next_h][next_w]) {
            dfs(next_h, next_w);
        }
    }
}

int main() {
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    while (scanf("%d%d", &w, &h) && w != 0 && h != 0) {
        memset(visited, false, sizeof(visited));
        count = 0;
        //read data
        for (int cur_h = 0; cur_h < h; ++ cur_h) {
            for (int cur_w = 0; cur_w < w; ++ cur_w) {
                scanf("%d", &n);
                if (n == 1) {
                    flag[cur_h][cur_w] = true;
                }
                else {
                    flag[cur_h][cur_w] = false;
                }
            }
        }
        //use dfs to count 
        for (int cur_h = 0; cur_h < h; ++ cur_h) {
            for (int cur_w = 0; cur_w < w; ++ cur_w) {
                if (flag[cur_h][cur_w] && ! visited[cur_h][cur_w]) {
                    ++ count;
                    dfs(cur_h, cur_w);
                }
            }
        }
        printf("%d\n", count);
    }
    

    return 0;
}
