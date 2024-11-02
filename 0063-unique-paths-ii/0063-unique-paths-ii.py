class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        row = len(obstacleGrid)
        column = len(obstacleGrid[0])

        ans = [[None]*column for i in range(row)]
        ans[0][0] = 1 if (obstacleGrid[0][0] == 0)  else 0
        
        # cell with obstacle can't be accessed. their ans = 0

        for i in range (1, row):
            ans[i][0] = ans[i-1][0] if (obstacleGrid[i][0] == 0) else 0

        for i in range (1, column):
            ans[0][i] = ans[0][i-1] if (obstacleGrid[0][i] == 0) else 0

        r = 1
        while(r < row) : 
            c = 1
            while(c < column):
                if (obstacleGrid[r][c] == 0): 
                    ans[r][c] = ans[r-1][c] + ans[r][c-1]
                else:
                    ans[r][c] = 0
                c+=1
            r+=1
        print(ans)
        return ans[row-1][column-1]
