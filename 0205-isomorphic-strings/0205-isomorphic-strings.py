def isIsomorphicHelper(s: str, t: str) -> bool:
    replacement : Dict[str, str] = {}

    # converting s to t
    for i in range(0, len(s)):
        if(s[i] in replacement) : 
            if(t[i] != replacement[s[i]]):
                return False
        else:
            replacement[s[i]] = t[i]
    return True

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if(len(s) != len(t)) : return False
        
        return (isIsomorphicHelper(s,t) and isIsomorphicHelper(t,s))