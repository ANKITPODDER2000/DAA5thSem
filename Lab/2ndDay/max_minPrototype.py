def max_min(i,j):
    if i==j:
        return a[i],a[j]
    elif i==j-1:
        return max(a[i],a[j]),min(a[i],a[j])
    else:
        mid = (i+j)// 2
        max1,min1 = max_min(i,mid)
        max2,min2 = max_min(mid+1,j)
        return max(max1,max2),min(min1,min2)

a = [10,20,51,68,80,5]
max_a,min_a = max_min(0,len(a)-1)
print("Max is ",max_a)
print("Min is ",min_a)