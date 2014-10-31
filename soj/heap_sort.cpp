#include <iostream>
#include <cstdio>

using namespace std;

void max_heapify(int *a, int i, int heap_size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = 0;
    if (l < heap_size && a[l] > a[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r < heap_size && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        max_heapify(a, largest, heap_size);
    }
}

void build_max_heap(int *a, int len) {
    for (int i = len / 2; i >= 0; -- i) {
        max_heapify(a, i, len);
    }
}

void head_sort(int *a, int len) {
    build_max_heap(a, len);
    for (int i = len - 1; i > 0; -- i) {
        swap(a[0], a[i]);
        max_heapify(a, 0, i);
    }
}


int main() {

    freopen("input", "r", stdin);
    int a[14];
    for (int i = 0; i < 14; ++ i) {
        cin >> a[i];
    }
    head_sort(a, 14);
    for (int i = 0; i < 14; ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
