class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        l1, l2  = len(text1), len(text2)

        lcs = [ [None]* (l2+1) for i in range(l1+1)]
        
        lcs[0] = [0] * (l2+1)

        for row in lcs:
            row[0] = 0
        
        for r in range(1, l1+1) : 

            for c in range(1, l2+1):
                lcs[r][c] = (1+lcs[r-1][c-1] )if (text1[r-1] == text2[c-1]) \
                                else (max(lcs[r-1][c], lcs[r][c-1]))
        
        return lcs[l1][l2]