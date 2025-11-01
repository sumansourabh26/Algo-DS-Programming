class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if(len(nums)==1) : 
            return 1
        current_empty = None
        current_num_idx = 0
        current_comparator_idx = 1
        
        while current_comparator_idx < len(nums):
            
            if(nums[current_num_idx] == nums[current_comparator_idx]):
                if(not current_empty):
                    current_empty = current_comparator_idx
            else:
                if(current_empty):
                    nums[current_empty] = nums[current_comparator_idx]
                    current_empty+=1
                current_num_idx = current_comparator_idx
            current_comparator_idx+=1
            
        return (current_empty) if current_empty else current_num_idx+1
        