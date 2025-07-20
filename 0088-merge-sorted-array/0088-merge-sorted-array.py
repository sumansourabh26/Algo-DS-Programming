class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m -1
        j = n -1
        f = m+n-1
        while( j >= 0):
            if(nums1[i] >= nums2[j]) and (i >= 0):
                nums1[f] = nums1[i]
                i -= 1
            else:
                nums1[f] = nums2[j]
                j-=1
            f-=1