from collections import defaultdict

def bt(temp_count, count_dict, index, ans , distinct_keys ):
    if(index == len(count_dict)):
        temp_arr = []
        for k, v in temp_count.items():
            for i in range(v):
                temp_arr.append(k)
        ans.append(temp_arr)
        return
    
    i = 0
    for i in range(0, count_dict[distinct_keys[index]]+1) : 
        temp_count[distinct_keys[index]] = i
        bt(temp_count, count_dict, index+1, ans , distinct_keys )


from typing import List
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        count_dict = defaultdict(int)

        for i in nums:
            count_dict[i] += 1
        
        distinct_keys = list(count_dict.keys())
        temp_count = {key : 0 for key in distinct_keys}
        ans = []
        index = 0
        bt(temp_count, count_dict, index, ans, distinct_keys )
        return ans

        
