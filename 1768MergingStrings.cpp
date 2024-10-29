class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Result holds the resulting string
        string result = "";
        // i starts at the first iteration of the word
        int i = 0;
        // while loop that iterates each element in word1 and word2 as long as theres letters left in the word
        while (i < word1.length() || i < word2.length()) {
            // If the word isn't at the end it will add the current letter to the result list
            if (i < word1.length()) {
                result += word1[i];
            }

            if (i < word2.length()) {
                result += word2[i];
            }
            // iterate to the next element
            i++;
        }

        return result;
    }
};