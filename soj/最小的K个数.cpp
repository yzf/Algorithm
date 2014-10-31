#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int Max = 200000;
/**
 * 在data中找出最小的need个数
 * 使用快排的思想
 */
int partition(int *data, int len, int start, int end) {
    int index = (start + end) >> 1;
    swap(data[index], data[end]);

    int small = start - 1;
    for (index = start; index < end; ++ index) {
        if (data[index] < data[end]) {
            ++ small;
            if (small != index) {
                swap(data[index], data[small]);
            }
        }
    }
    ++ small;
    swap(data[small], data[end]);
    return small;
}
void kSmall(int *data, int len, int need, int *result) {
    int start = 0;
    int end = len - 1;
    int index = partition(data, len, start, end);
    while (index != need - 1) {
        if (index > need - 1) {
            end = index - 1;
            index = partition(data, len, start, end);
        }
        else {
            start = index + 1;
            index = partition(data, len, start, end);
        }
    }
    //把前k个数排序
    sort(data, data + need);
    for (int i = 0; i < need; ++ i) {
        result[i] = data[i];
    }
}

int main() {
    freopen("input", "r", stdin);

    int data[Max];
    int result[Max];
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &data[i]);
        }
        kSmall(data, n, k, result);
        for (int i = 0; i < k - 1; ++ i) {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[k - 1]);
    }   

    return 0;
}
