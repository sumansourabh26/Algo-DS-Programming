class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        neg_inc = nums[0] if(nums[0] < 0) else 0
        pos_inc = nums[0] if(nums[0] > 0) else 0
        ans = nums[0]
        
        for n in nums[1:]:
            if(n < 0) : 
                neg_inc_temp = neg_inc
                neg_inc = min(n, pos_inc * n)
                pos_inc =  neg_inc_temp * n
            elif(n>0):
                neg_inc = neg_inc*n
                pos_inc = max(pos_inc * n, n)
            else:
                neg_inc = 0
                pos_inc = 0
            ans = max(ans, pos_inc, neg_inc)
        return(ans)


