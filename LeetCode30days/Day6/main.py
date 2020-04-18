class Solution:
    def groupAnagrams(self, strs):
        Dict = dict()
        ans = []
        copystrs = strs[:]
        for i in range(len(strs)):
            copystrs[i] = sorted(copystrs[i])
            copystrs[i] = "".join(copystrs[i])
        
        for i in range(len(strs)):
            if copystrs[i] in Dict:
                Dict[copystrs[i]].append(strs[i])
            else:
                Dict[copystrs[i]] = [strs[i]]
        for i in Dict.keys():
            ans.append(Dict[i])
        return ans
s = Solution()