from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if(len(nums)  == 0):
            return 0
        
        nums.sort()


        ans = 1
        current_count = 1
        current_number = nums[0]

        for i in range(1, len(nums)):
            if(nums[i] == (nums[i-1]+1)):
                current_count +=1
            elif(nums[i] == (nums[i-1])):
                continue
            else:
                ans = int(max(current_count, ans))
                current_count = 1
            current_number = nums[i]
        
        ans = int(max(current_count, ans))
        return ans
            