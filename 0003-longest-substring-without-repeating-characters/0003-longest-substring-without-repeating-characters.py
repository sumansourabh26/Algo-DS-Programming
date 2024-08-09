class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(s ==""):
            return 0
        present_alphabet = set({s[0]})
        length = len(s)
        longest = 1
        l = r = 0
        
        while (r < (length-1)) :

            r = r + 1
            while((s[r] in present_alphabet)):
                present_alphabet.remove(s[l])
                l += 1
            present_alphabet.add(s[r])

            longest = max(longest, (r-l+1))
        
        return longest