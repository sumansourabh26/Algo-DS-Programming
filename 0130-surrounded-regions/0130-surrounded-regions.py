class Solution:

    def dfs(self, row, col) : 
        if(not((0<=row < self.row) and (0<=col < self.col))) : return
        if(self.board[row][col] == 'X') : return
        if(not self.captured[row][col]) : return

        self.captured[row][col] = False

        diffs = [(0,1), (1,0), (-1,0), (0,-1)]

        for diff in diffs: 
            dr, dc = diff
            self.dfs(row+dr, col+dc)


    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        self.board = board
        self.row = len(board)
        self.col = len(board[0])
        self.captured = [[True for i in range(self.col)] for j in range(self.row)]
        
        for i in range(self.row) : 
            if(self.board[i][0] == 'O') and (self.captured[i][0]):
                self.dfs(i,0) 
            if(self.board[i][self.col-1] == 'O') and (self.captured[i][self.col-1]):
                self.dfs(i,self.col-1) 
        
        for i in range(1, self.col-1) : 
            if(self.board[0][i] == 'O') and (self.captured[0][i]):
                self.dfs(0,i) 
            if(self.board[self.row-1][i] == 'O') and (self.captured[self.row-1][i]):
                self.dfs(self.row-1,i) 
        
        for i in range(self.row) : 
            for j in range(self.col) : 
                if((self.board[i][j] == 'O') and (self.captured[i][j])) : 
                    self.board[i][j] = 'X'
        


        





