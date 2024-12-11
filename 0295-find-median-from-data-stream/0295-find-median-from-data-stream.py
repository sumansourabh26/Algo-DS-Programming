from heapq import heappush, heappop


class MedianFinder:

    def __init__(self):
        self.max_heap = []
        self.min_heap = []
        self.size = 0
        self.median = 0
        
    def addNum(self, num: int) -> None:
        if(self.size%2):  #odd case (max heap is more already)
            if(num >= -self.max_heap[0]):
                heappush(self.min_heap, num)
            else:
                heappush(self.max_heap, -num)
                heappush(self.min_heap, -heappop( self.max_heap))
        else: #already even 
            if(self.size ==0 or (num <= -self.max_heap[0])):
                heappush(self.max_heap, -num)
            else:
                heappush(self.min_heap, num)
                heappush(self.max_heap, -heappop( self.min_heap))
                
        
        self.size+=1

    def findMedian(self) -> float:
        if(self.size % 2):
            return(-self.max_heap[0])
        else:
            return(round((self.min_heap[0] - self.max_heap[0])/2,1))
