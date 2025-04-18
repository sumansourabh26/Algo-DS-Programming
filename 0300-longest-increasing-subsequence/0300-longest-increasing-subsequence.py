from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        length = len(nums)
        lis = [0]*length
        lis[0] = 1
        
        max_lis_global = 1
        for i in range(1, length):
            
            max_lis = 0
            for j in range(0, i):
                if(nums[j] < nums[i]) : 
                    max_lis =  max(lis[j], max_lis )
            lis[i] = max_lis+1
            max_lis_global = max(max_lis_global, lis[i])
        
        return(max_lis_global)