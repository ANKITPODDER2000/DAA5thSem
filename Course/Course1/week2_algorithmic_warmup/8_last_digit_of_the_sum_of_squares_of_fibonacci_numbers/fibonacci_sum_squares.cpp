#include <iostream>

int fibonacci_sum_squares_naive(int n) {
    // write your code here
    if (n<=1)
        return n;
    unsigned long long int a = 0 , b = 1,c,sum = 1;
    for(int i=2;i<=n;i++)
    {
        c = a + b;
        a = b;
        b = c;
        sum += (c * c);
    }
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
