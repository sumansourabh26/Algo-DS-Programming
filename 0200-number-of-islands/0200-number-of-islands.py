
from typing import List


class Solution:
    def propagate_island(self,i,j): 
        if not ((0<= i < self.rows) and (0 <= j < self.cols)): return
        if(self.grid[i][j] == '0') : return
        if(self.is_visited[i][j]) : return
        self.is_visited[i][j] = True
        for (dr,dc) in [(-1,0), (1,0), (0,1), (0,-1)]:
            self.propagate_island(i+dr, j+dc) 

    def numIslands(self, grid: List[List[str]]) -> int:
        self.rows, self.cols = len(grid), len(grid[0])
        self.grid = grid
        self.is_visited = [[False for col in range(self.cols)] for row in range(self.rows)]

        grid_counter = 0
        for i, row in enumerate(grid):
            for j, item in enumerate(row) : 
                if (self.grid[i][j] == '1') and (not self.is_visited[i][j]):
                    grid_counter += 1
                    self.propagate_island(i,j)
        return grid_counter

