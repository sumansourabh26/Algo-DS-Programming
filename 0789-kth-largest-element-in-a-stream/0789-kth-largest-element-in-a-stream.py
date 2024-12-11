import heapq
import copy
class KthLargest:

    def __init__(self, k: int, stream: List[int]):
        self.nums = stream[0:min(k, len(stream))]
        self.k = k
        heapq.heapify(self.nums)
        for i in range(k, len(stream)):
            self.add(stream[i])
        

    def add(self, val: int) -> int:
        
        if(len(self.nums) == self.k ):
            if(self.nums[0] < val):
                heapq.heappop(self.nums)
                heapq.heappush(self.nums,val)
        else:
            heapq.heappush(self.nums,val)
        return(self.nums[0])
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)