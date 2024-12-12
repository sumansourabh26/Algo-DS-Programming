class Solution:
    def rob(self, nums: List[int]) -> int:
        
        max_ex = 0
        max_inc = 0

        for n in nums:
            temp = max_ex
            max_ex = max(max_ex, max_inc)
            max_inc = temp + n
        
        return max(max_inc,max_ex )