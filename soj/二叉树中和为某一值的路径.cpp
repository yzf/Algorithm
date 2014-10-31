#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int Max = 10001;

struct Node {
    int vi, l, r;
} nodes[Max];

void dfs(int nodeId, vector<int> &path, int sum, int target) {
    if (nodeId == -1) {
        return;
    }
    sum += nodes[nodeId].vi;
    path.push_back(nodeId);
    if (nodes[nodeId].l == -1 && nodes[nodeId].r == -1) {
        if (sum == target) {
            printf("A path is found:");
            for (int i = 0; i < path.size(); ++ i) {
                printf(" %d", path[i]);
            }
            printf("\n");
        }
    }
    if (nodes[nodeId].l < nodes[nodeId].r) {
        dfs(nodes[nodeId].l, path, sum, target);    
        dfs(nodes[nodeId].r, path, sum, target);
    }
    else {
        dfs(nodes[nodeId].r, path, sum, target);
        dfs(nodes[nodeId].l ,path, sum, target);
    }
    path.pop_back();
}

int main() {
    freopen("input", "r", stdin);

    int n, k;
    int vi, l, r;
    vector<int> path;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 1; i <= n; ++ i) {
            scanf("%d%d%d", &vi, &l, &r);
            nodes[i].vi = vi;
            nodes[i].l = l;
            nodes[i].r = r;
        }
        path.clear();
        printf("result:\n");
        dfs(1, path, 0, k);
    }

    return 0;
}
