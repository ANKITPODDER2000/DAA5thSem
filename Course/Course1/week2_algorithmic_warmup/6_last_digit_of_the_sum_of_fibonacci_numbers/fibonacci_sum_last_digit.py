# Uses python3
import sys

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum_      = 1

    for _ in range(2,n+1):
        previous,current = previous%10,current%10
        previous, current = current, previous + current
        sum_ += current
        sum_ %= 10

    return sum_ % 10

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum_naive(n))
