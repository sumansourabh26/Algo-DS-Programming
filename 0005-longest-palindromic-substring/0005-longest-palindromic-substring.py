class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)


        is_palindrome = [ ([None] * l) for i in range(l) ]

        for i in range(l):
            is_palindrome[i][i] = True
        max_len = [0,0]

        if(l < 2) : print( max_len)
        for i in range(l-1):
            if(s[i] == s[i+1]): 
                is_palindrome[i][i+1]  = True
                max_len = [i,i+1]
            else:
                is_palindrome[i][i+1]  = False
                
                
                
        for palind_len in range(3, l+1):
            i = 0
            
            while((i+palind_len-1) < l):
                
                if ( is_palindrome[i+1][i+palind_len-2] and (s[i] == s[i+palind_len-1])):
                    is_palindrome[i][i+palind_len-1] = True
                    max_len = [i,i+palind_len-1]
                else:
                    is_palindrome[i][i+palind_len-1] = False
                i+=1
                
        
        
        # print(is_palindrome)
        return (s[max_len[0]: max_len[1]+1])
        
 
 