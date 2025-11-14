class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        min_change = [float('inf')]*(amount+1)
        min_change[0] = 0
        
        for i in range(1,amount+1):
                
            for c in coins:
                if((i-c) >= 0):
                    min_change[i] = min(min_change[i], min_change[i-c] + 1)

        return -1 if (min_change[amount] == float('inf') )else (min_change[amount])
        