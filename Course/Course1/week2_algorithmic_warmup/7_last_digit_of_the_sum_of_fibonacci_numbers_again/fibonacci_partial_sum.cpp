#include <iostream>
#include <vector>
using std::vector;

unsigned long long get_fibonacci_partial_sum_naive(unsigned long long from, unsigned long long to) {
    unsigned long long sum = 0;

    unsigned long long current = 0;
    unsigned long long next  = 1;

    if(from<=1){
        sum = 1;
    }

    for (long long i = 2; i <= to; ++i) {
        new_current = next;
        next = next + current;
        current = new_current;

        if (i >= from) {
            sum += current;
        }
    }

    return sum % 10;
}

int main() {
    unsigned long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
