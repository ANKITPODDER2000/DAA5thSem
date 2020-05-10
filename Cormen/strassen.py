import numpy as np

def strassen(A,B):
    if A.shape[0]==1 and B.shape[0]==1:
        return A*B
    else:
        shape = A.shape[0]//2
        C = []
        A11 = A[:shape,:shape]
        A12 = A[:shape,shape:]
        A21 = A[shape:,:shape]
        A22 = A[shape:,shape:]
        
        B11 = B[:shape,:shape]
        B12 = B[:shape,shape:]
        B21 = B[shape:,:shape]
        B22 = B[shape:,shape:]
        
        C11 = strassen(A11 , B11) + strassen(A12 , B21)
        C12 = strassen(A11 , B12) + strassen(A12 , B22)
        C21 = strassen(A21 , B11) + strassen(A22 , B21)
        C22 = strassen(A21 , B12) + strassen(A22 , B22)
        
        C = np.vstack(( np.hstack((C11,C12)) , np.hstack((C21,C22))))
        
        return C

n = int(input("Enter no of rows : "))
B = []
print("Enter Matrix A : ")
A = [np.array([int(i) for i in input().split(" ")]) for j in range(n)]
A = np.array(A)
print("Enter Matrix B : ")
B = [np.array([int(i) for i in input().split(" ")]) for j in range(n)]
B = np.array(B)

c = strassen(A,B)
print("Result is : ")
for i in c:
    print(i)