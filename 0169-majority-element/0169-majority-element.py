class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        e = nums[0]
        count = 0
        
        for i in nums:
            if(i == e):
                count+=1
            else:
                count-=1
                if(count<0):
                    e = i
                    count = 1
        
        return e
        