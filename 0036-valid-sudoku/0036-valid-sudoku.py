ints = [i for i in range(1,10)]
def validate(l : list[str]) : 
    existing = set()
    for i in l:
        if str(i).isdecimal() : 
            if int(i) not in ints : 
                return False
            if i in existing:
                return False
            existing.add(i)
        elif i != '.' : 
            return False
    return True

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            if(not validate(row)) : 
                return False
        columns = [list(col) for col in zip(*board)]
        for col in columns:
            if(not validate(col)) : 
                return False
        boxes = [ [board[i][j] for i in range(r, r+3) for j in range(c, c+3)] for r in (0, 3, 6) for c in (0, 3, 6)]
        for box in boxes:
            if(not validate(box)) : 
                return False
        return True