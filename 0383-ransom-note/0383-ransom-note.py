class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return all((magazine.count(c) - ransomNote.count(c)) >= 0 for c in set(ransomNote))
        