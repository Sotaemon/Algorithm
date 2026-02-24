#include <iostream>

void
exchang_int(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int
sort_bubble(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j - 1] > a[j]) {
                exchang_int(&a[j - 1], &a[j]);
            }
        }
    }
    return 0;
}

int
main(void) {
    int a[] = { 5, 6, 2, 2, 1, 7, 3, 9, 1 };
    int n = sizeof(a) / sizeof(int);
    int ans = sort_bubble(a, n);
    if (ans)
        return 1;
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
    return 0;
}