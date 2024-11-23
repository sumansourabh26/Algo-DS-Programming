class Solution:
    def trap(self, height: List[int]) -> int:

        '''
                              1 i
        [0,1,0,2,1,0,1,3,2,1,2,1]
         i 0 
        '''
        length = len(height)

        
        water = 0
        left_max = 0
        right_max = 0
        left, right = 0, length-1

        while(left <= right):
            if(left_max < right_max):
                water += max(left_max - height[left], 0)
                left_max = max(left_max, height[left])
                left+=1
            else:
                water += max(right_max - height[right], 0)
                right_max = max(right_max, height[right])
                right-=1
        return(water)


        
        return water