from collections import defaultdict
import copy
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        '''
        'a' : 1 (# of a in s1 - # of a in s2 = 1)
        '''
        if(len(s2) < len(s1)) : return (False)
        
        intial_diff = defaultdict(int)
        for c in s1:
            intial_diff[c] += 1

        difference = copy.deepcopy(intial_diff)
        
        i = 0

        while(i < len(s1)):
            difference[s2[i]] -= 1 
            if(difference[s2[i]] == 0):
                difference.pop(s2[i])
            i+=1
            
        if(len(difference) == 0 ) : 
            return True
        right_index = i # excluded
        left_index = i - len(s1) #included
        
        while(right_index < len(s2)):
            difference[s2[right_index]] -= 1 
            difference[s2[left_index]] += 1 
            if(difference[s2[right_index]] == 0):
                difference.pop(s2[right_index])
            if(difference[s2[left_index]] == 0):
                difference.pop(s2[left_index])  
            right_index +=1
            left_index += 1

            if(len(difference) == 0 ) : 
                return True

        return False


                 


        