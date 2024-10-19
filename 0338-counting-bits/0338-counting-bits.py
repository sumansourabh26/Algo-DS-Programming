class Solution:
    def countBits(self, n: int) -> List[int]:
        a = [0]*(n+1)
        a[0] = 0
        
        i = 1
        while i <= (n):
            a[i] = a[i>>1] + (i&1)
            i+=1
        return a
        