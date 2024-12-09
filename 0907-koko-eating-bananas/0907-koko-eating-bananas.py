def valid(speed, piles, h):
    # -(a // -b)
    return ((sum([-(pile//-speed) for pile in piles])) <= h)

class Solution:
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()

        left, right = 1, piles[-1] 
        while left < right:
            mid = left + ((right - left) >> 1)
            if valid(mid, piles, h):
                right = mid
            else:
                left = mid + 1
        return left


        