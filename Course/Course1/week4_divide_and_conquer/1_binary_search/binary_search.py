# Uses python3
import sys

def binary_search(a, l,u , key):
    if l<=u:
        mid = (l+u) // 2
        if a[mid] == key:
            return mid
        elif a[mid] > key:
            return binary_search(a,l,mid-1,key)
        else:
            return binary_search(a,mid+1,u,key)
    else:
        return -1
    
    

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1: n + 1]
    for x in data[n + 2:]:
        print(binary_search(a, 0 , len(a)-1,x), end = ' ')
