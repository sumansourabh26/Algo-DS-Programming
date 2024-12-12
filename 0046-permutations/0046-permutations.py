class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        taken = [False] * len(nums)
        ans = []
        
        def bt(temp_arr):
            if(len(temp_arr) == len(nums)):
                ans.append(temp_arr.copy())
                return
            
            for i in range(0, len(nums)):
                if(not taken[i]):
                    taken[i] = True
                    temp_arr.append(nums[i])
                    bt(temp_arr)
                    temp_arr.pop()
                    taken[i] = False
        
        temp_arr = []
        bt(temp_arr)
        return(ans)



        