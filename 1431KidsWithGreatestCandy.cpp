class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // 1. Create vector of bool values
        // 2. Create a variable that holds the first value of the list
        // 3. For loop thru the list and compare the variable and check for highest

        std::vector<bool> results;
        int currentHighest = *std::max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            int CurrentKid = candies[i] + extraCandies;
            if (CurrentKid >= currentHighest) {
                results.push_back(true);
            } else {
                results.push_back(false);
            }
        }

        return results;
    }
};