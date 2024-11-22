class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        // Iterate thru vector nums
        for (int i = 0; i < nums.size(); i++) {
            
            // for each iteration we create a complement value 
            // the complement value is target - nums[i]
            // so basically if the first value is 2 the complement would be 9 - 2 = 7
            int complement = target - nums[i];

            // then for that current complement we want to check if the key exists for that value in the current
            // numMap, if it exists then we return, if it doens't exist we move forward

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // this would return the index of the key and the indecie of the current value
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};