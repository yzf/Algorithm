#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int Max = 1000;

int main() {
    freopen("input", "r", stdin);

    int m, n;
    int data[Max][Max];
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &data[i][j]);
            }
        }

        int u = 0, d = m - 1, l = 0, r = n - 1;
        for (; u <= d && l <= r; ++ u, -- d, ++ l, -- r) {
            for (int i = l; i <= r; ++ i) {
                printf("%d ", data[u][i]);
            }
            for (int i = u + 1; i <= d; ++ i) {
                printf("%d ", data[i][r]);
            }
            if (u != d)
                for (int i = r - 1; i >= l; -- i) {
                    printf("%d ", data[d][i]);
                }
            if (l != r)
                for (int i = d - 1; i > u; -- i) {
                    printf("%d ", data[i][l]);
                } 
        }
        printf("\n");
    }

    return 0;
}
