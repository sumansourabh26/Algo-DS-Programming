def helper(s, s_i, t, t_i) : 
    if(s_i == len(s))  : 
        return True
    if( t_i == len(t)):
        return False
    if(s[s_i] == t[t_i]): 
        return helper(s, s_i+1, t, t_i+1)
    return helper(s, s_i, t, t_i+1)

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        return helper(s,0,t,0)

        