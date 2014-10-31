#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 1000000;

int n, data[Max], m, k;

int getFirstK(int *data, int len, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k) {
        if ((middleIndex > 0 && data[middleIndex - 1] != k)
                || middleIndex == 0) {
            return middleIndex;
        }
        else {
            end = middleIndex - 1;
        }
    }
    else if (middleData > k) {
        end = middleIndex - 1;
    }
    else {
        start = middleIndex + 1;
    }
    return getFirstK(data, len, k, start, end);
}

int getLastK(int *data, int len, int k, int start, int end) {
    if (start > end) {
        return -1;
    } 
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k) {
        if ((middleIndex < len - 1 && data[middleIndex + 1] != k)
                || middleIndex == len - 1) {
            return middleIndex;
        }
        else {
            start = middleIndex + 1;
        }
    }
    else if (middleData > k) {
        end = middleIndex - 1;
    }
    else {
        start = middleIndex + 1;
    }
    return getLastK(data, len, k, start, end);
}

int getNumberOfK(int *data, int len, int k) {
    int number = 0;
    if (len > 0) {
        int first = getFirstK(data, len, k, 0, len - 1);
        int last = getLastK(data, len, k, 0, len - 1);
        if (first > -1 && last > -1) {
            number = last - first + 1;
        }
    }
    return number;
}

int main() {
    freopen("input", "r", stdin);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &data[i]);
        }
        scanf("%d", &m);
        while (m --) {
            scanf("%d", &k);
            printf("%d\n", getNumberOfK(data, n, k));
        }
    }

    return 0;
}
