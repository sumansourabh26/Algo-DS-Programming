from collections import deque

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = deque()
        ans = [None]*len(temperatures)
        for i, item in enumerate(temperatures):

            
            while(len(stack) > 0 and stack[-1][0] < item):
                top = stack.pop()
                ans[top[1]] = i - top[1]
            
            stack.append((item,i))
        
        while(len(stack) > 0):
            top = stack.pop()
            ans[top[1]] = 0
            
        return(ans)
        