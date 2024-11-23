#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start

from typing import List

from numpy import number


class Solution:
	def twoSum(self, numbers: List[int], target: int) -> List[int]:
		
		l = 0
		r = len(numbers)-1

		while l < r:
			_sum  = numbers[l] + numbers[r]

			if _sum < target:
				l += 1
			elif _sum > target:
				r -= 1
			else :
				return [l+1, r+1]                
		return []


				
		
# @lc code=end

