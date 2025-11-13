class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        r,c = len(matrix), len(matrix[0])
        # find row first
        low, high = 0, r-1

        while(low <= high):
            mid = int((low+high)/2)

            mid_value = matrix[mid][0]
            if(mid_value == target) : return True
            elif(mid_value < target) : low = mid + 1
            else : high = mid -1
        
        candidate_row = high

        low, high = 0, c-1

        while(low <= high):
            mid = int((low+high)/2)

            mid_value = matrix[candidate_row][mid]
            if(mid_value == target) : return True
            elif(mid_value < target) : low = mid + 1
            else : high = mid -1
        return False

        