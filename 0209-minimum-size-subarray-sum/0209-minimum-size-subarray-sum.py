class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, r = 0, 0
        sum_ = 0
        min_length = float('inf')
        found = False
        while (l <= r):
            if(sum_<target) and (r < len(nums)):
                sum_ += nums[r]
                r+=1
            elif(sum_ >= target):
                sum_ -= nums[l]
                l+=1
            else:
                break
            
            if(sum_ >= target) : 
                found = True
                min_length = min(min_length, r-l)
                
        return(min_length if found else 0)
        