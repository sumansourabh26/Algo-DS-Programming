def is_valid(position):
    count = len(position)
    for i in range(count):
        for j in range(count):
            if(i == j): continue
            if(position[i][0] == position[j][0]) : return False
            if(position[i][1] == position[j][1]) : return False
            if(abs(position[i][0] - position[j][0]) == \
            abs (position[i][1] - position[j][1]) ) : return False
    return True

default_pos = [
    "Q.......",
    ".Q......",
    "..Q.....",
    "...Q....",
    "....Q...",
    ".....Q..",
    "......Q.",
    ".......Q"
]

def bt(position, row, ans, n):
    if(not is_valid(position)) : return

    if(row == n) : 
        ans.append(position.copy())
        return
    
    for i in range (n):
        position.append((row, i))
        bt(position, row+1, ans,n)
        position.pop()
        
        
from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        position = []
        row = 0
        ans = []
        bt(position, row, ans, n)
        string_ans = []
        default_str = '.'*n
        for position in ans:
            current = []
            for row in position:
                s = default_str[:row[1]]+'Q'+default_str[row[1]+1:]
                current.append( s)
            string_ans.append( current)
        return string_ans