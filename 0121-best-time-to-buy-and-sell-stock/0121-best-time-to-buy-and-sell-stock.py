class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_ = prices[0]
        profit = 0
        
        for i in range(1, len(prices)):
            if(prices[i-1] < min_):
                min_ = prices[i-1]
            
            p = prices[i] - min_
            if(p > profit):
                profit = p
        
        return profit