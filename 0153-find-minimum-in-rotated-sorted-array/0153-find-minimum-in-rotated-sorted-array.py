class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        if(nums[0] <= nums[-1]) : return (nums[0])

        # 7 0 1 2 3 4 5 6
        # 6 7 0 1 2 3 4 5
        # most left element with 
        l, r = 0 , len(nums)-1
        while(l < r):
            mid = l + (r-l)//2

            if(nums[mid] < nums[0]):
                r = mid
            else:
                l = mid + 1
        return(nums[l])
        