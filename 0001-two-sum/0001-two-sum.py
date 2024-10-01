# https://leetcode.com/problems/two-sum/


def tuple_sort(t):
    return t[0]


class Solution(object):
    def twoSum(self, nums, target):
        
        index_dict = {}
        for index in range(len(nums)):
            index_dict[nums[index]] = index
        
        for i in range(len( nums)) : 
            num = nums[i]
            reminder = target - num
            if(reminder in index_dict) and (index_dict[reminder] != i): 
                return(i, index_dict[reminder])
        
        