class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l,r = 0,0
        
        unique_set = set()
        ans = 0
        
        for r in range(0, len(s)):
            incoming = s[r]
            while(l<= r):
                if (incoming in unique_set):
                    unique_set.remove(s[l])
                    l+=1
                else:
                    unique_set.add(incoming)
                    break
                
            ans = max(ans, r-l+1)
        return(ans)