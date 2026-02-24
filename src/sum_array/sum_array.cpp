#include <iostream>

int sum_array(int n, int a[]) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

int main(void) {
    int a[] = {2, 5, 4, 0, 4};
    int n = sizeof(a) / sizeof(int);
    int sum = sum_array(n, a);
    std::cout << sum << std::endl;
    return 0;
}