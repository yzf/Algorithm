#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 100000;

int main() {
    freopen("input", "r", stdin);

    int n;
    int data;
    while (scanf("%d", &n) != EOF) {
        map<int, int> count;
        int half = n >> 1;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &data);
            ++ count[data];
        }
        map<int, int>::iterator it = count.begin();
        for ( ; it != count.end(); ++ it) {
            if (it->second > half) {
                printf("%d\n", it->first);
                break;
            }
        }
        if (it == count.end()) {
            printf("-1\n");
        }
    }

    return 0;
}
