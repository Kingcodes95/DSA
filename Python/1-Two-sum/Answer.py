        # map to add values and their indecies (indexs)
        # nums_map is a dictionary initialized to store numbers from nums as keys and their indices(indexs) as values
        nums_map = {}
    

        # for each index in range(len(nums)) -> range is how many numbers to iterate thru, len is the length of a variable 
        for i in range(len(nums)):

            # the complement is target - nums[i], so if the target is 9 then the complement would be 9 - nums[i] which is the current value of the index
            complement = target - nums[i]

            # if the complement is in the nums_map, which means the value has been seen before then it returns the current i, index value and the nums_map[complement] which is the other values index
            if complement in nums_map:
                return [i, nums_map[complement]]

            # if the value is not found then we want to store the current value as the key and the index i as the value
            nums_map[nums[i]] = i

        # if we don't find anything then we return nothing.
        return []