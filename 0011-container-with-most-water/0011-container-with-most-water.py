
from typing import List

class Solution:
	def maxArea(self, height: List[int]) -> int:
		left = 0
		right = len(height)-1
		maximum_water = min(height[left], height[right])*(right-left)
		
		while right > left:
			
			if(height[left] > height[right]):
				right -= 1
			else:
				left += 1
			
			maximum_water = max(min(height[left], height[right])*(right-left), maximum_water)
		return maximum_water

