class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_ = prices[0]
        profit = 0
        
        for i in range(1, len(prices)):
            min_ = min(min_, prices[i-1])
            profit = max(profit,prices[i] - min_)
        
        return profit