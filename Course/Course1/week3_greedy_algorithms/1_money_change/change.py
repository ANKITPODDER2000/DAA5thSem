# Uses python3
import sys

def get_change(m):
    #write your code here
    rupee10 = m // 10
    rupee5  = (m % 10) // 5
    rupee1  = m - (rupee10 * 10) - (rupee5 * 5)

    return rupee10 + rupee5 + rupee1

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
