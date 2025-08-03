class Solution:
    def isPalindrome(self, a: str) -> bool:
        a = a[::-1]
        a = a.lower()
        a = ''.join(c for c in a if c.isalnum())
        return (a == a[::-1])
        