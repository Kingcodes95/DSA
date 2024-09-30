
// since it's just one string of each, you could just put them in order and then compare them
// this is O(nlogn) because of the sorting operation

// Should come back to this problem to use a more efficent algo and fix complexity.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};