class Solution:
    def trap(self, height: List[int]) -> int:

        '''
                              1 i
        [0,1,0,2,1,0,1,3,2,1,2,1]
         i 0 
        '''
        length = len(height)
        # left_max = [None]*length
        right_max = [None]*length
        
        # left_max[0] = 0
        right_max[length-1] = 0

        for i in range(1, length):
            # left_max[i] = int(max(left_max[i-1], height[i-1]))
            right_max[length-1 - i] = (max(right_max[length- i], height[length- i]))
        
        water = 0
        left_max = height[0]
        for i in range(1, length):
            # print(left_max)
            water +=  max(min(left_max, right_max[i]) - height[i], 0)
            left_max = max(left_max, height[i])


        
        return water