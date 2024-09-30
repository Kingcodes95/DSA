#include <vector>
#include <iostream>
#include <unordered_map>

// Most efficent way to solve this was Hashmap, O(n) where n is the size of the array.
//unordered_map, unordered_set.

int main() {

    std::vector<int> nums = {7, 2, 11, 15};
    int target = 9;

    std::unordered_map<int, int> numMaps; //Map to store numbers and their indices(targets basically)
    for (int i = 0; i < nums.size(); i++) { // for loop to iterate thru each number
        int complement = target - nums[i]; // complement is the target - nums[i], the values in the list so you complement + nums = target
        if (numMaps.find(complement) != numMaps.end()) {
            return {numMaps[complement], i}; // indinces found (not incorrect on leetcode)
        }
        numMaps[nums[i]] = i; // add current member to map.
    }

    return {};

}