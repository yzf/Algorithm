#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 1000;

void dcFind(bool &flag, int &target, int data[][Max],
        int beRow, int beCol,
        int enRow, int enCol) {
    if (flag || enRow < beRow || enCol < beCol) {
        return ;
    }
    if (enRow == beRow && enCol == beCol) {
        flag = (target == data[beRow][beCol] ? true : false);
        return ;
    }

    int midRow = (beRow + enRow) >> 1;
    int midCol = (beCol + enCol) >> 1;

    int small = data[beRow][beCol];
    int big = data[midRow][midCol];
    if (target >= small && target <= big) {
        dcFind(flag, target, data, 
                beRow, beCol, 
                midRow, midCol); 
    } 
    small = data[beRow][midCol + 1];
    big = data[midRow][enCol];
    if (target >= small && target <= big) {
        dcFind(flag, target, data, 
                beRow, midCol + 1,
                midRow, enCol);
    }

    small = data[midRow + 1][beCol];
    big = data[enRow][midCol];
    if (target >= small && target <= big) {
        dcFind(flag, target, data,
                midRow + 1, beCol,
                enRow, midCol);
    }
    small = data[midRow + 1][midCol + 1];
    big = data[enRow][enCol];
    if (target >= small && target <= big) {
        dcFind(flag, target, data,
                midRow + 1, midCol + 1,
                enRow, enCol);
    }
}

int main() {
    freopen("input", "r", stdin);

    int m, n, t;
    bool flag;
    int data[Max][Max];

    while (scanf("%d%d", &m, &n) != EOF) {
        scanf("%d", &t);
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &data[i][j]);
            }
        }
        flag = false;
        if (t >= data[0][0] && t <= data[m - 1][n - 1]) {
            dcFind(flag, t, data, 0, 0, m - 1, n - 1);
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
