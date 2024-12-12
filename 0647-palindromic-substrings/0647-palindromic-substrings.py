
class Solution:
    def countSubstrings(self, s: str) -> str:
        
        l = len(s)
        if(l < 2) : return l

        ispalindrome = [ [None]*l for i in range(l)]

        for i in range(l):
            ispalindrome[i][i] = True

        ans = l

        for i in range(l-1):
            if (s[i] == s[i+1]):
                ispalindrome[i][i+1] = True
                ans +=1
            else:
                ispalindrome[i][i+1] = False
            

        for gap in range(2,l):
            i = 0

            while((i + gap ) < l):
                ispalindrome[i][i+gap] = ispalindrome[i+1][i+gap-1] and (s[i] == s[i+gap])
                if(ispalindrome[i][i+gap]) : 
                    ans +=1
                i+=1

        return (ans)

        
        