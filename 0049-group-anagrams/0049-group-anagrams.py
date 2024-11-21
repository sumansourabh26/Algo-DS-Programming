from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        distinct_nums = defaultdict(list)

        for item in strs:
            distinct_nums[hash(''.join(sorted(item)))].append(item)
        
        return(list(distinct_nums.values()))
        


        