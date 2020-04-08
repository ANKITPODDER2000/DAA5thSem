class Solution:
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        a = 0
        b = 0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[a],nums[b] = nums[b],nums[a]
                a+=1
            b+=1
        return nums
s = Solution()