def search_binary(left, right, nums, target, cols):
    
    
    mid = (left+right) >> 1 # mid 
    if(nums[mid//cols][mid%cols] == target) : return (True)
    
    if(left >= right ) : return (False)
    if(nums[mid//cols][mid%cols] > target):
        return(search_binary(left, mid, nums, target, cols))
    else:
        return(search_binary(mid+1, right, nums, target, cols))



class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])

        return search_binary(0, rows*cols-1, matrix, target, cols)

        