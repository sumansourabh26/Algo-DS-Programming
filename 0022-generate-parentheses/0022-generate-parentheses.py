from collections import deque

def computeStack(stack, state, open_count, total_paren, ans):
    if(state < 0):
        return
    if(open_count > total_paren):
        return
    
    if(state == 0 and open_count == total_paren):
        ans.append(''.join(stack))
        return

    stack.append('(')
    computeStack(stack, state+1, open_count+1, total_paren, ans)
    stack.pop()
    
    stack.append(')')
    computeStack(stack, state-1, open_count, total_paren, ans)
    stack.pop()


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = deque()
        ans = []
        computeStack(stack, 0, 0, n, ans)
        return ans
        
        