def count(a):
    li = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]
    c = 0
    while a!=0:
        c += li[a & 15]
        a = a >> 4
    return c
a = (10**8)+1
b = (10**5)+1
mape = [0]*10**8
print("ok")
for i in range(a):
    for j in range(b):
        mape[i^j] = count(i^j)
        print(i^j)
    print(mape)