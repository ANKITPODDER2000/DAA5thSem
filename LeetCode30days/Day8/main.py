class Solution:
    def backspaceCompare(self, S , T):
        str1 = ""
        str2 = ""
        
        for i in S:
            if i=="#":
                str1 = str1[:-1]
            else:
                str1 = str1 + i
        for i in T:
            if i=="#":
                str2 = str2[:-1]
            else:
                str2 = str2 + i
        
        if str1==str2:
            return True
        return False

S = Solution()
            
        