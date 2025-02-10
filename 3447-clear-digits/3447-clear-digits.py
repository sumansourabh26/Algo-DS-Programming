class Solution:
    def clearDigits(self, s: str) -> str:
        stack = deque()

        for c in s:
            try:
                int(c)
                stack.pop()
            except ValueError as ve:
                stack.append(c)
        return(''.join(list(stack)))
        