# ^^^^^|^^^^^^^^^
# first element < 0th element


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        while(l < r):
            mid = (l+r)//2

            if(nums[mid] < nums[0]):
                r = mid
            else:
                l = mid + 1
                
        return nums[l%len(nums)]
        


        