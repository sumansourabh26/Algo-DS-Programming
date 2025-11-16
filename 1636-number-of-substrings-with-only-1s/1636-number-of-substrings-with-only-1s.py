ex = int(1e9+7)
class Solution:
    def numSub(self, s: str) -> int:
        counter = 0
        ans = 0

        for c in s:
            if(c == '1') : 
                counter += 1
            else:
                ans =  int((ans + int((counter*(counter+1))/2))%ex)
                counter = 0
        ans = int((ans + int((counter*(counter+1))/2)) %ex)
        return ans
        