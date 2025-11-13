class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        #search first
        nums.append(float('inf'))
        l, r = 0, len(nums)
        found = False
        while(l <=r ):
            mid = (l+r)//2
            if(nums[mid] > target) : 
                r = mid - 1
            elif(nums[mid] == target) : 
                r = mid - 1
                found = True
            else:
                l = mid + 1
        if not found : return [-1, -1]
        beginning = l


        l, r = 0, len(nums)
        while(l <=r ):
            mid = (l+r)//2
            if(nums[mid] <= target) : 
                l = mid + 1
            else:
                r = mid - 1

        
        return[beginning, r]


            
        