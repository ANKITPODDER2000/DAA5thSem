# Uses python3
from sys import stdin

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(2,n + 1):
        previous, current = current, previous + current
        sum += (current%10) * (current % 10)

    return sum % 10

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum_squares_naive(n))
