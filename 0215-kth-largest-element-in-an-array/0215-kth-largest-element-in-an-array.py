from typing import List
class MinHeap:
    def __init__(self):
        self.data = []
    
    def push(self, element) : 
        self.data.append(element)
        
        index = len(self.data) -1
        
        while (index > 0) :
            if(self.data[index] < self.data[(index-1)//2]) : 
                self.data[index], self.data[(index-1)//2] =  self.data[(index-1)//2],  self.data[index]
                index = (index-1)//2
            else:
                break

    def pop(self):
        ans = self.data[0]
        self.data[0] = self.data[-1]
        self.data.pop()
        
        index = 0
        
        while(index < len(self.data)) : 
            
            minimum = index
            left = index*2 + 1
            right = index*2 + 2
            if(left < len(self.data) and (self.data[left] < self.data[minimum])) :
                minimum = left
            if(right < len(self.data) and (self.data[right] < self.data[minimum])) :
                minimum = right
            if(index == minimum) : 
                break
            self.data[index], self.data[minimum] = self.data[minimum], self.data[index]
            index = minimum   
            
        return ans     

    def heapify(self, arr: List[int]) :
        self.data = arr
        init_index = (len(arr)-2)//2
        
        for i in range(init_index, -1, -1): 
            
            index = i
            while(index < len(self.data)) : 
                minimum = index
                left = index*2 + 1
                right = index*2 + 2
                if(left < len(self.data) and (self.data[left] < self.data[minimum])) :
                    minimum = left
                if(right < len(self.data) and (self.data[right] < self.data[minimum])) :
                    minimum = right
                if(index == minimum) : 
                    break
                self.data[index], self.data[minimum] = self.data[minimum], self.data[index]
                index = minimum   
    def peak(self):
        return(self.data[0])
        
        
    
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = MinHeap()
        for i in range(0, k) : 
            heap.push(nums[i])    
            
        for i in range(k, len(nums)) : 
            if(heap.peak() < nums[i]) : 
                heap.pop()
                heap.push(nums[i])       
        return(heap.peak())  

        

# Solution().findKthLargest([3,2,1,5,6,4], 2)