#include <iostream>

int
merge(int a[], int p, int q, int r) {
    int l_n = q - p + 1;
    int r_n = r - q;
    int left[l_n], right[r_n];

    for (int i = 0; i < l_n; ++i)
        left[i] = a[p + i];
    for (int i = 0; i < r_n; ++i)
        right[i] = a[q + i + 1];

    int k = p;
    int i = 0, j = 0;

    while (i < l_n && j < r_n) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    while (i < l_n) {
        a[k++] = left[i++];
    }
    while (j < r_n) {
        a[k++] = right[j++];
    }

    return 0;
}

int
merge_sort(int a[], int p, int r) {
    if (p >= r) {
        return 0;
    }
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
    return 0;
}

int
main(void) {
    int a[] = { 4, 5, 2, 3, 1, 0, 7, 5 };
    int ans = merge_sort(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
    return 0;
}