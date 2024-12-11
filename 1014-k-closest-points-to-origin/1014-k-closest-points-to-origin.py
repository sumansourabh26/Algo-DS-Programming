import heapq
from math import sqrt
from dataclasses import dataclass

@dataclass
class point:
    x: int
    y: int

    def __lt__(self, other):
        return((self.x*self.x +self.y*self.y) < (other.x*other.x +other.y*other.y))

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        list_point = [point(p[0], p[1]) for p in points]

        list_point.sort()
        list_point = list_point[0:k]

        ans = [[p.x, p.y] for p in list_point]
        return (ans)

        




        