# Uses python3
import sys
from random import randint

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(2,n+1):
        previous, current = current, previous + current
        previous,current = previous % 10 , current % 10
    return current % 10
def fib(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(2,n+1):
        previous, current = current, previous + current

    return current % 10


if __name__ == '__main__':
    input = sys.stdin.read()
    """
    i = 0
    print("Iter := ",end="")
    while True:
        num = randint(1,1000)
        if fib(num)!=get_fibonacci_last_digit_naive(num):
            break
        if i%10==0:
            print(i,end=" ")
        i+=1
    print()
    """
    n = int(input)
    print(get_fibonacci_last_digit_naive(n))


