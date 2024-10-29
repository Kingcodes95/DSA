
// This is not the most efficent way to solve this
// need to come back and fix complexity and time.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a map with both string and vector<string> to create string and a vector to store the other versions of the answer.
        std::unordered_map<string, vector<string>> map;

        //iterate thru and sort the word, then add to the map if there is a similar match.
        for (auto x: strs) {
            string word = x;
            sort(word.begin(), word.end());
            map[word].push_back(x);
        }

        //add answer to the answer map from the original mapping.
        vector<vector<string>> answer;
        for (auto x: map) {
            answer.push_back(x.second);
        }

        return answer;
    }
};

// 1. Create a unordered_map that holds string and another vector of strings
// 2. create a for loop for x in string
// 3. create variable word = x
// 4. sort the word
// 5. for that x in the vector insert the word to the correct one
// 6. create a vector for the answer
// 7. for each x in map map.push_back(x.second)
// 8. return the ans vector