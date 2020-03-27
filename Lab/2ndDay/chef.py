test = input()
test = int(test)
ans = [0]*test
for count in range(test):
    n,m = input().split(" ")
    n,m = int(n),int(m)
    Dict = dict()
    f = [int(x) for x in input().split()]
    try:
            p = [int(x) for x in input().split()]
    except:
        p = [float(x) for x in input().split()]
    for i in range(n):
        if f[i] not in Dict:
            Dict[f[i]] = p[i]
        else:
            Dict[f[i]] += p[i]
    ans[count] = min(list(Dict.values()))
for i in ans:
    print(i)