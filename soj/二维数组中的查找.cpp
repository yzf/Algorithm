#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 1000;
int m, n, t;
int data[Max][Max];

bool binaryFind(int *line, int len, int target) {
    int be = 0, en = len;
    int mid;
    bool result = false;
    while (be < en) {
        mid = (be + en) >> 1;
        if (line[mid] > target) {
            en = mid;
        }
        else if (line[mid] < target) {
            be = mid + 1;
        }
        else {
            result = true;
            break;
        }
    }
    return result;
}

bool findNumber() {
    for (int i = 0; i < m; ++ i) {
        if (binaryFind(data[i], n, t)) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input", "r", stdin);
        
    while (scanf("%d%d", &m, &n) != EOF) {
        scanf("%d", &t);
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &data[i][j]);
            }
        }
        if (findNumber()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
