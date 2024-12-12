class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        l = len(s)
        possible = [False] * (l+1)

        possible[0] = True

        for i in range(1, l+1):
            
            
            for word in wordDict : 
                if(i-len(word) >= 0): 
                    possible[i] = (s[i-len(word) :i] == word) and possible[i-len(word)]
                    if(possible[i]) : break
        return(possible[l])