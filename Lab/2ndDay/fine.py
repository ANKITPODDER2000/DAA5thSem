d1,m1,y1 = input().split()
d1,m1,y1 = int(d1),int(m1),int(y1)

d2,m2,y2 = input().split()
d2,m2,y2 = int(d2),int(m2),int(y2)

if d1==d2 and m1==m2 and y1==y2:
    print("0")
elif y1>y2:
    print("10000")
elif y2>y1:
    print("0")
elif m1==m2 and d1<=d2:
    print("0")
elif m1>m2:
    print((m1-m2)*500)
else:
    if (d1-d2)*15 >0:
        print((d1-d2)*15)
    else:
        print(0)