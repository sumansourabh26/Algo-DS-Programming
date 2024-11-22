class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        '''
            1   2   3   4
            1   1   2   6   24 
            24  24  12  4   1
        '''
        total_len = len(nums)+1

        left_product = [1]*(total_len)
        right_product = [1]*(total_len)

    
        for i in range(1,total_len):
            left_product[i] = left_product[i-1]*nums[i-1]
            right_product[total_len - i -1] = right_product[total_len - i]*nums[total_len - i-1]

        ans = [None]*len(nums)
        for i in range(0,len(nums)):
            ans[i] = left_product[i] * right_product[i+1]
        return(ans)


        