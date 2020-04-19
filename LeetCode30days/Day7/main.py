class Solution:
    def countElements(self, arr):
        
        count = 0
        Dict = dict()
        
        for i in arr:
            
            if i in Dict:
                Dict[i]+=1
                
            else:
                Dict[i] = 1
            
        for i in Dict.keys():
            if i+1 in Dict:
                count += Dict[i]
        
        return count
            
S = Solution()
