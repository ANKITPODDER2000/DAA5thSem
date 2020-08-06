#include <iostream>

long long int gcd_naive(long long int a, long long int b) {
  if(b==0)
    return a;
  else
    return gcd_naive(b,a%b);
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
