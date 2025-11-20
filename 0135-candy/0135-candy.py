class Solution:
    def candy(self, rating: List[int]) -> int:

        candies = [1] * len(rating)

        #look forward from left
        for i in range(1, len(rating)):
            if(rating[i] > rating[i-1]) : 
                candies[i] = candies[i-1]+1

        for i in range(len(rating)-1, 0, -1):
            if (rating[i] < rating[i-1]) and (candies[i] >= candies[i-1]): 
                candies[i-1] = candies[i]+1

        return(sum(candies))
                