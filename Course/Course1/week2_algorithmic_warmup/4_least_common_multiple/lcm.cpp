#include <iostream>

unsigned long long int gcd_naive(unsigned long long int a, unsigned long long int b) {
  if(b==0)
    return a;
  else
    return gcd_naive(b,a%b);
}

long long int lcm_naive(long long int a, long long int b) {
	return (unsigned long long int)((a * b) / gcd_naive(a,b));
}

int main() {
  unsigned long long int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
