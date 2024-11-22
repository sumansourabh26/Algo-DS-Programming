from collections import defaultdict
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        counter = defaultdict(int)

        for num in nums:
            counter[num] += 1
        
        count_pair = [(i, count) for i, count in counter.items() ]

        count_pair.sort(key = lambda x: x[1], reverse = True)

        ans = []
        # print(count_pair)
        for i in range(k):
            ans.append(count_pair[i][0])
        return(ans)


        