class Solution:
    def numTrees(self, n: int) -> int:
        ans = [None]*(n+1)
        ans[1] = 1
        ans[0] = 1
        
        for i in range(2, n+1):
            ans[i] = 0

            for j in range (0, i):
                ans[i] += (ans[j] * ans[i-j-1])
        # print(ans)

        return(ans[n])


        