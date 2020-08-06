#include <iostream>

unsigned long long get_fibonacci_huge_naive(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long tmp_previous = 0;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        previous %= m;
        current  %= m;
    }

    return current % m;
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
