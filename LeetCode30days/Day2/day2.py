class Solution:
    def isHappy(self, n: int) -> bool:
        number = n
        sq = []
        while(number != 1):
            ans = 0
            while(number != 0):
                ans += (number%10) ** 2
                number //= 10
            if ans in sq:
                return False
            sq.append(ans)
            number = ans
        return True
s = Solution()