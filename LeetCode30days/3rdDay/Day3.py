class Solution:
    def maxSubArray(self, nums):
        table = [0] * (len(nums))
        table[0] = nums[0]
        maxVal = table[0]
        for i in range(1,len(nums)):
            if nums[i]+table[i-1] >= nums[i]:
                table[i] = nums[i] + table[i-1]
            else:
                table[i] = nums[i]
            if table[i] > maxVal:
                maxVal = table[i]
        return maxVal
s = Solution()



'''
class Solution:
    def maxSubArray(self, nums):
        maxV = max(nums)
        maxvalind = [0]*nums.count(maxV)
        j = 0
        for i in range(len(nums)):
            if nums[i]==maxV:
                maxvalind[j] = i
                j+=1
        
        retmax = maxV
        
        for i in maxvalind:
            m = maxV
            sum_cal = 0
            for k in range(i,len(nums)):
                sum_cal += nums[k]
                if m < sum_cal:
                    m = sum_cal
            sum_cal = 0
            m1 = m
            for k in range(i,-1,-1):
                sum_cal += nums[k]
                if m < sum_cal+m1-maxV:
                    m = sum_cal+m1-maxV
                elif m < sum_cal:
                    m = sum_cal
                print(sum_cal)
            if m>retmax:
                retmax = m
        return retmax
s = Solution()


class Solution:
    def maxSubArray(self, nums):
        m = max(nums)
        copy = m
        max_value = nums.index(m)
        sum_cal = 0
        for i in range(max_value,len(nums)):
            sum_cal += nums[i]
            if m < sum_cal:
                m = sum_cal
        sum_cal = 0
        m1 = m
        for i in range(max_value,-1,-1):
            sum_cal += nums[i]
            if m < sum_cal+m1-copy:
                m = sum_cal+m1-copy
            elif m < sum_cal:
                m = sum_cal
        return m
'''                