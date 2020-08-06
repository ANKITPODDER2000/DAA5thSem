# Uses python3
import sys

def optimal_sequence(n):
    seq = [0] * (n+1)
    parent = [0] * (n+1)
    SEQ = [1,2,3]
    for i in range(2,n+1):
        seq[i] = i
        for s in SEQ:
            if s <= i:
                if s==1:
                    temp = seq[i-1] + 1
                    if temp<seq[i]:
                        parent[i] = i-1
                        seq[i] = temp
                elif s==2 and i%2==0:
                   temp = seq[i//2] + 1
                   if temp<seq[i]:
                        seq[i] = temp
                        parent[i] = i//2
                elif s==3 and i%3==0:
                    temp = seq[i//3] + 1
                    if temp<seq[i]:
                        seq[i] = temp
                        parent[i] = i//3
    ans = [0]*(seq[n]+1)
    i = seq[n]
    p = n
    while p>0:
        ans[i] = p
        p = parent[p]
        i -= 1
    #print(seq)
    #print(parent)
    return ans

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
