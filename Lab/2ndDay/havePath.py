"""
def havePath(s,e):
    #print(s,e)
    reached = reached_from[e]
    #print(reached_from)
    #print("===",reached_from[e])
    while True:
        #print("===",reached)
        if reached ==s:
            return True
        if reached==-1:
            return False
        node = reached
        reached = reached_from[node]
        
    
def findpath():
    s,e = input("\nEnter the starting and ending node : ").split()
    s,e = int(s),int(e)
    if havePath(s,e):
        print("\nIt has Path")
    else:
        print("\nIt has no Path")

def BFS():
    if len(queue)==0:
        return
    else:
        node = queue.pop(0)
        print(node,end=" ")
        for i in range(len( matrix[node][:])):
            if matrix[node][i]==1 and visited[i]==0:
                queue.append(i)
                visited[i] = 1
                reached_from[i] = node
        BFS()
        
def takeMatrix(n):
    matrix = []
    for _ in range(n):
        li = []
        li = [int(x) for x in input().split(" ")]
        matrix.append(li)
    return matrix

def isConnected():
    for i in visited:
        if i==0:
            return False
    return True

size = int(input("Enter total no of Edges in graph : "))
queue = []
visited = [0]*size
reached_from = [-1]*size
matrix = takeMatrix(size)
queue.append(0)
visited[0] = 1
print("\n==========\nBFS is : ",end="")
BFS()
print()
findpath()
if isConnected():
    print("\nGraph is connected")
else:
    print("\nGraph is not connected")
    
"""

class Solution:
    # Write your code here
    def __init__(self):
        self.queue = []
        self.stack = []
    def pushCharacter(self,ch):
        self.stack.append(ch)
    def enqueueCharacter(self,ch):
        self.queue.append(ch)
    def popCharacter(self):
        return self.stack.pop()
    def dequeueCharacter(self):
        return self.queue.pop(0)


# read the string s
s=input()
#Create the Solution class object
obj=Solution()   

l=len(s)
# push/enqueue all the characters of string s to stack
for i in range(l):
    obj.pushCharacter(s[i])
    obj.enqueueCharacter(s[i])
    
isPalindrome=True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
''' 
for i in range(l // 2):
    if obj.popCharacter()!=obj.dequeueCharacter():
        isPalindrome=False
        break
#finally print whether string s is palindrome or not.
if isPalindrome:
    print("The word, "+s+", is a palindrome.")
else:
    print("The word, "+s+", is not a palindrome.")    