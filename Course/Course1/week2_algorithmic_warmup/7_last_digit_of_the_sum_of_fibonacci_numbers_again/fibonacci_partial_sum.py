# Uses python3
import sys

def fibonacci_partial_sum_naive(from_, to):
    if to<=1:
        return to
    
    sum_ = 0
    current = 0
    next  = 1

    if(from_<=1):
        sum_ = 1

    for i in range(2,to + 1):
        current, next = next, current + next
        current,next = current%10,next%10
        if i >= from_:
            sum_ += next
            sum_ %= 10

    return sum_ % 10


if __name__ == '__main__':
    input = sys.stdin.read();
    from_, to = map(int, input.split())
    print(fibonacci_partial_sum_naive(from_, to))