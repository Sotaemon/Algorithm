#include <iostream>

int
sort_insertion(int n, int a[]) {
    int key = 0, j = 0;
    for (int i = 1; i < n; ++i) {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
    return 0;
}

int
main() {
    int a[] = { 5, 2, 4, 6, 1, 3 };
    int n = sizeof(a) / sizeof(int);
    int ans = sort_insertion(n, a);
    if (ans == 0) {
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}