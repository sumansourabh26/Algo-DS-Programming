from collections import deque
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        current_tokens = deque()

        for token in tokens:
            if(token in {'+', '-', '*','/'}):
                t1 = current_tokens.pop()
                t2 = current_tokens.pop()
                current_tokens.append(int(eval(f"{t2} {token} {t1}")))
            else:
                current_tokens.append(token)
            # print(current_tokens)
        return (int(current_tokens[0]))

