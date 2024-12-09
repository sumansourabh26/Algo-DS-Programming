
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        l, r = 0, len(nums)-1
        while(l < r):
            mid = l + (r-l)//2
            if(target <= nums[mid] ):
                r = mid
            else:
                l = mid+1
        if(nums[l] == target):
            return l
        else:
            return -1
        