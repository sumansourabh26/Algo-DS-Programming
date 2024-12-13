class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        nums.sort()
        total = sum(nums)
        if(total&1) : return False
        
        target = total//2
        is_possible = [ [False] * (len(nums)+1)  for i in range(target+1)]

        is_possible[0][0] = True

        #is_possible[i][j] = if it is possible to get sum = i, by considering items upto nums[j]

        for w in range(0, target+1):

            for j in range(1, len(nums)+1):

                if(w < nums[j-1]): 
                    is_possible[w][j] = is_possible[w][j-1]
                else:
                    is_possible[w][j] =  is_possible[w][j-1] or is_possible[w - nums[j-1]][j-1]
            
        return is_possible[target][len(nums)]
