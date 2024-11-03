class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        l1 = len(word1)+1
        l2 = len(word2)+1

        # dp = [ [0]*l2 for i in range(l1) ]

        dp = [i for i in range(l2)]
        
        for i in range (1, l1):

            new_dp = [None] * l2
            new_dp[0] = i
            for j in range (1, l2):
                if(word1[i-1] == word2[j-1]) : 
                    new_dp[j] = dp[j-1] 
                else : 
                    new_dp[j] = 1+ min(dp[j-1], dp[j], new_dp[j-1])
            dp = new_dp
            del new_dp
        
        return dp[l2-1]

        