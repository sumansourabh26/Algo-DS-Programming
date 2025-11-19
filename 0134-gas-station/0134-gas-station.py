class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        min_index = None
        min_value = float('inf')

        current_fuel = 0

        for i in range(len(gas)):
            current_fuel += gas[i] - cost[i]
            
            if(current_fuel < min_value) : 
                min_index = i
                min_value = current_fuel
        

        if (min_index+1) == len(gas) : 
            return 0
        return (min_index + 1)
