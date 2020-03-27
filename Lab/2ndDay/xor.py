test = int(input())
ans = []
for _ in range(test):
    n,q = input().split()
    n,q = int(n),int(q)
    li = [int(x) for x in input().split()]
    for o in range(q):
        odd = 0
        even = 0
        p = int(input())
        for i in li:
            a = p ^ i
            if bin(a).count('1')%2==0:
                even +=1
            else:
                odd+=1
        ans.append((even,odd))
    