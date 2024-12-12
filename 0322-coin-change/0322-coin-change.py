class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        coin_needed = [-1] * (amount+1)
        coin_needed[0] = 0

        for i in range(1, amount+1):
            coin_needed[i] = 1000000000
            for coin in coins:
                if (i - coin) >= 0 : 
                    coin_needed[i] = min(coin_needed[i], coin_needed[i-coin] + 1)
        
        return(coin_needed[amount] if (coin_needed[amount] != 1000000000) else -1)
