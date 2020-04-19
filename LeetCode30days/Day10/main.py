class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []

    def push(self, x: int) -> None:
        self.arr.append(x)
        return None

    def pop(self) -> None:
        self.arr.pop()
        return None

    def top(self) -> int:
        try:
            return self.arr[-1]
        except:
            return None

    def getMin(self) -> int:
        try:
            return min(self.arr)
        except:
            return None


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()