"""
    ===================DFS=====================
    >Take no. of Node/vertices From User 
    >Take Adjacent Matrix
"""

def DFS():
    if len(queue)==0:
        return
    else:
        p = queue.pop()
        print(p,end="  ")
        for i in range(len(adj_mat[p])):
            if adj_mat[p][i]==1 and visit[i]==0:
                queue.append(i)
                visit[i] = 1
        DFS()


node = int(input("Enter no of nodes : "))
adj_mat = [0]*node
visit = [0]*node
queue = []
start = int(input("Enter the Starting Node : "))
print("Enter the Adjacent Matrix : ")
for i in range(node):
    a = []
    a = [int(x) for x in input().split()]
    adj_mat[i] = a
queue.append(start)
visit[start] = 1
print("DFS is : ",end="")
DFS()