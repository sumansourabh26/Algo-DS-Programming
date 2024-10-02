from typing import List
import sys

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        diff = sys.maxsize
        
        ans = 0
        # a + b + c  = 0
        for i, a in enumerate(nums):
            if (i > 0 and nums[i] == nums[i-1]):
                i += 1
                continue

            if (i > (len(nums)-3)):
                break

            new_target = target - a

            l = i + 1
            r = len(nums)-1
            

            while l < r:
                _sum = nums[l] + nums[r]
                if _sum == new_target:
                    ans = _sum + a
                    return (ans)

                _diff = abs(_sum - new_target)
                
                if(_diff < diff):
                    ans = _sum + a
                    diff = _diff

                if _sum < new_target:
                    l += 1
                else:
                    # ans = min(ans, abs(_sum - new_target))
                    r -= 1

        return (ans)

# a = Solution()
# print(a.threeSumClosest([1,1,1,0], -100))

