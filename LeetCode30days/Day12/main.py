class Solution:
    def lastStoneWeight(self, stones):
        try:
            while len(stones)!=1:
                stones = sorted(stones,reverse=True)
                stones[0] = stones[0] - stones[1]
                stones[1] = 0
                stones[0],stones[1] = stones[1],stones[0]
                stones = stones[1:]
                if stones[0]==0:
                    stones = stones[1:]
            return stones[0]
        except:
            return 0

s = Solution()