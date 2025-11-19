class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        min_index = None
        min_value = float('inf')

        current_fuel = 0

        for i in range(len(gas)):
            current_fuel += gas[i] - cost[i]
            
            if(current_fuel < min_value) : 
                min_index = i
                min_value = current_fuel
        
        if current_fuel < 0 : return -1

        if (min_index+1) == len(gas) : 
            return 0
        return (min_index + 1)
