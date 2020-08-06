#include <iostream>

int get_fibonacci_last_digit_naive(int n) 
{
    if( n <=1) 
        return n; 
    unsigned long long a[n+1];
    a[0] = 0;
    a[1] = 1;
    for(unsigned long long i=2;i<=n;i++)
      a[i] = a[i-1] + a[i-2];
    for(int i=0;i<=n;i++)
      std::cout << a[i] << "\n";
    return a[n] % 10; 
} 

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
