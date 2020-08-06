# Uses python3
import sys
def merge(s,mid,e):
    temp1 = [0] * (e-s+1)
    temp2 = [0] * (e-s+1)
    temp3 = [0] * (e-s+1)
    i = s
    j = mid+1
    k = 0
    
    while i<=mid or j<=e:
        
        if i>mid:
            temp1[k] = ratio[j]
            temp2[k] = weights[j]
            temp3[k] = values[j]
            j+=1
        elif j>e:
            temp1[k] = ratio[i]
            temp2[k] = weights[i]
            temp3[k] = values[i]
            i+=1
        elif ratio[i]>=ratio[j]:
            temp1[k] = ratio[i]
            temp2[k] = weights[i]
            temp3[k] = values[i]
            i+=1
        else:
            temp1[k] = ratio[j]
            temp2[k] = weights[j]
            temp3[k] = values[j]
            j+=1
        k+=1
    k = s
    for i in range(0,e-s+1):
        ratio[k] = temp1[i]
        weights[k] = temp2[i]
        values[k] = temp3[i]
        k+=1

def mergeSort(s,e):
    if e>s:
        mid = (s+e)//2
        mergeSort(s,mid)
        mergeSort(mid+1,e)
        merge(s,mid,e)

def get_optimal_value(capacity, weights, values):
    value = 0.0
    l = len(values)
    
    for i in range(l):
    	ratio[i] = values[i] / weights[i]
        
    mergeSort(0,l-1)
    
    i = 0
    while i<l and capacity>0:
        if weights[i] <= capacity:
            value += values[i]
            capacity -= weights[i]
        else:
            value += ratio[i] * capacity
            capacity = 0
        i+=1
        
    return value



if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    #data = list(map(int, input().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    ratio = [0] * len(values)
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))

