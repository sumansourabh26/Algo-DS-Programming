class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        differences = defaultdict(int)
        for i, item in enumerate(nums) : 
            differences[item-i] += 1

        differences = differences.values()
        sum_sq = sum(differences)
        sum_sq = sum_sq**2
        sq_sum_diff = sum([diff**2 for diff in differences])
        return((sum_sq - sq_sum_diff)//2)