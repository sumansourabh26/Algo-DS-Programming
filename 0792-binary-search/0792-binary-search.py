def search_binary(left, right, nums, target):
    
    
    mid = (left+right) >> 1 # mid 
    if(nums[mid] == target) : return mid
    
    if(left >= right ) : return (-1)
    if(nums[mid] > target):
        return(search_binary(left, mid, nums, target))
    else:
        return(search_binary(mid+1, right, nums, target))



class Solution:
    def search(self, nums: List[int], target: int) -> int:

        return search_binary(0, len(nums)-1, nums, target)
        