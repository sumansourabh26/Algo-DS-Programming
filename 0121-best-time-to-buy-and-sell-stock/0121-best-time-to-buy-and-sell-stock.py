class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        max_profit = 0

        min_left_price = 10000

        for price in prices:
            max_profit = max(max_profit, price - min_left_price)
            min_left_price = min(min_left_price, price)
        
        return max_profit