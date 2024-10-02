from typing import List



class Solution:
	def threeSum(self, nums: List[int]) -> List[List[int]]:
		nums.sort()
		ans = set()

		# a + b + c  = 0
		for i, a in enumerate(nums):
			if(i > 0 and nums[i] == nums[i-1]):
				i += 1
				continue
				
			if (i > (len(nums)-3)):
				break

			target = -1 * a
					
			l = i + 1
			r = len(nums)-1

			while l < r:
				_sum  = nums[l] + nums[r]
				if _sum == target:
					
					ans.add((nums[i], nums[l], nums[r]))
					l += 1
				elif _sum < target:
					l += 1
				else:
					r -= 1
		
		_ans = [list(e) for e in ans]
		return(ans)


		