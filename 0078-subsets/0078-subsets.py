
def populate_index(index, nums, temp_array, ans):
    if(index == len(nums)):
        ans.append(temp_array.copy())
        return

    populate_index(index+1, nums, temp_array, ans)
    
    temp_array.append(nums[index])
    populate_index(index+1, nums, temp_array, ans)
    temp_array.pop()

    


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        temp_array = []
        populate_index(0, nums, temp_array, ans)
        return(ans)


        