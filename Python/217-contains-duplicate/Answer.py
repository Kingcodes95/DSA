        num_set = set()

        # simple length of nums basically
        n = range(len(nums))

        # for each iteration of i in the range/length of nums
        for i in n:

            # check if the value of nums[i] is already in the set
            if nums[i] in num_set:
                return True
            # if its not in the set then add that value to the set
            num_set.add(nums[i])
        return False