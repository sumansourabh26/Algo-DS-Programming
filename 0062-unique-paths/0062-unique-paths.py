class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        ans = [[1]*n]*m
        
        r = 1
        while(r < m) : 
            c = 1
            while(c < n):
                ans[r][c] = ans[r-1][c] + ans[r][c-1]
                c+=1
            r+=1

        return ans[m-1][n-1]


