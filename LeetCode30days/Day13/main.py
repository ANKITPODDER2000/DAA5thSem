class Solution:
    def findMaxLength(self, nums):
        maxVal = 0
        for i in range(len(nums)):
            for j in range(i+1+maxVal,len(nums)):
                c0 = nums[i:j+1].count(0)
                c1 = nums[i:j+1].count(1)
                if c0==c1:
                    if maxVal < j-i + 1:
                        maxVal = j-i+1
        return maxVal

s = Solution()