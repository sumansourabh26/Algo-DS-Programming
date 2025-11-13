def is_peak(i, nums):
    return((nums[i] > nums[i-1]) and (nums[i] > nums[i+1]))

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        nums.append(float('-inf'))
        
        l, r = 0, len(nums)-2

        while(l<=r) : 
            if(is_peak(l, nums)): return l
            if (is_peak(r, nums)) : return r
            
            mid = int((l+r)/2)
            if(is_peak(mid, nums)) : return mid
            if(nums[mid+1] > nums[mid]) : l = mid+1
            else: r = mid - 1
        


        
        