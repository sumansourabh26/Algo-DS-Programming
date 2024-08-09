#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start


def extra(count_map):

    max_count = -1
    max_alpha = -1
    for i, item in count_map.items():
        if(item > max_count) : 
            max_count = item
            max_alpha = i

    return sum([(item if(i != max_alpha) else 0) for i,item in count_map.items() ])
    


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        r = 1
        count_map = {
            s[l] : 1
        }
        ans = 1
        length = len(s)
        

        
        while (r < length) : 
            count_map[s[r]] = count_map.get(s[r], 0) + 1
            while(extra(count_map) > k) :
                count_map[s[l]] -= 1
                l+=1
            ans = max(ans, r-l+1)
            r += 1

        return ans

# a = Solution()
# s = "BAAAB"
# k = 2
# print(a.characterReplacement(s,k))

# @lc code=end

