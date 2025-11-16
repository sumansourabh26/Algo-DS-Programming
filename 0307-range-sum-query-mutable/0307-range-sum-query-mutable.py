
def populate_tree(segment_arr, curr_i, nums, l, r):
    if( l == r):
        segment_arr[curr_i] = nums[l]
        return nums[l]
    mid = (l+r)//2

    left = populate_tree(segment_arr, curr_i*2+1, nums, l, mid)
    right = populate_tree(segment_arr, curr_i*2+2, nums, mid+1, r)

    segment_arr[curr_i] = left+right
    return segment_arr[curr_i]
    
def update_tree(segment_arr, curr_i, index: int, delta: int, l, r ):
    if(index < l) or (index > r) : 
        return 0
    segment_arr[curr_i] += delta
    if(l != r):
        mid = (l+r)//2
        if(index <= mid) : update_tree(segment_arr, curr_i*2+1, index, delta, l, mid )
        else: update_tree(segment_arr, curr_i*2+2, index, delta, mid+1, r)
        
def sum_tree(segment_arr, root, sl, sr, left, right):
    if(sr < left) or (sl > right) : return 0
    
    if(left <= sl) and (sr <= right) : return segment_arr[root]
    
    mid = (sl+sr)//2
    root_result = 0
    root_result += sum_tree(segment_arr, root*2+1, sl, mid, left, right)
    root_result += sum_tree(segment_arr, root*2+2, mid+1, sr, left, right) 
    
    return root_result
    

class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.segment_array = [0] * 4*len(nums)
        populate_tree(self.segment_array,0, nums, 0, len(nums)-1)
    
    def update(self, index: int, val: int) -> None:
        delta = val - self.nums[index]
        self.nums[index] = val
        update_tree(self.segment_array, 0, index, delta , 0, len(self.nums)-1 )
    
    def sumRange(self, left: int, right: int) -> int:
        return sum_tree(self.segment_array, 0, 0, len(self.nums)-1, left, right)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)