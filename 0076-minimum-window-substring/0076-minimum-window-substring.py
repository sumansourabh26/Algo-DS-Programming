from collections import defaultdict
def is_valid(left_sum, right_sum, target):
    count = defaultdict(int, {i: right_sum[i] - left_sum[i] for i in right_sum})
    return(all([count[i] >= target[i] for i in target ]))

class Solution:
    def minWindow(self, s: str, t: str) -> str:

        target_set = set(t)
        target = defaultdict(int)

        for c in t:
            target[c] += 1

        left_sum = defaultdict(int)
        right_sum = defaultdict(int)
        left = -1 #array index that need to be excluded
        right = -1 # array index that need to be included
        # if(s[0] in target_set):
        #     right_sum[s[0]] = 1
        '''
        ADOBECODEBANC
        between (left,right].
        '''
        ans_found = False
        ans = [0, len(s)]
        len_s = len(s)
        while(right < len_s):
            if(is_valid(left_sum, right_sum, target)):
                ans_found = True
                if((ans[1] - ans[0]+1) >  (right-left)):
                    ans = [left+1, right]
                
                left+=1
                if(s[left] in target_set):
                    left_sum[s[left]] += 1


            else:
                right+=1
                if(right == len_s) : break
                if(s[right] in target_set):
                    right_sum[s[right]] += 1
                
                


        if(is_valid(left_sum, right_sum, target)):
            ans_found = True
            if((ans[1] - ans[0]+1) >  (right-left)):
                ans = [left+1, right]
        
        if( not ans_found):
            return ""
        else : 
            return(s[ans[0]: ans[1]+1])









