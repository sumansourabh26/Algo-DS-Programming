class Solution:
    def canJump(self, nums: List[int]) -> bool:

        current_position = 0
        max_position = 0
        while (current_position < len(nums)):
            jump = nums[current_position]
            max_position = max(max_position, current_position + jump)
            if(max_position >= (len(nums)-1)) : return True
            
            if(current_position < max_position): 
                current_position += 1
            else: return False



