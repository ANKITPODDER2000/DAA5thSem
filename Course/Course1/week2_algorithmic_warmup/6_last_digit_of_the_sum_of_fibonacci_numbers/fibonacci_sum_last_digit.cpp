#include <iostream>

int fibonacci_sum_naive(unsigned long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long sum      = 1;
    unsigned long long tmp_previous = 0;

    for (unsigned long long i = 2; i <=n; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
