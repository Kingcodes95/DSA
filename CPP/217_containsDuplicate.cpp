

//This is the best time complexity of O(n), n being the size of the array.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //find elements that appear twice in the array
        //implement unordered_set<int>
        std::unordered_set<int> seen;

        //iterate thru array nums and set index 1 value to variable
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            //check if variable exists in the set already
            if (seen.find(num) != seen.end()) {
                return true;
            }
            //if it doesn't add it to set.
            seen.insert(num);
        }
        return false;
    }
};