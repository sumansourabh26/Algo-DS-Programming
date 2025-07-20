class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        r = len(nums)-1
        i = 0
        
        while(i <= r) : 
            if(nums[i] == val) : 
                nums[i] = nums[r]
                nums[r] = 0
                r -=1
            else:
                i+=1
        return r+1