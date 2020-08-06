# Uses python3
import sys

def get_change(m):
    coin = [0] * (m+1)
    coins = [1,3,4]
    for i in range(1,m+1):
        coin[i] = i
        for c in coins:
            if i>=c:
                temp = coin[i-c] + 1
                if temp < coin[i]:
                    coin[i] = temp
    #print(coin)
    return coin[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    #m = int(input())
    print(get_change(m))
