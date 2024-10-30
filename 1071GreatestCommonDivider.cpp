class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if both strings equal eachother forwards and backwards 
        // then return the substr(0, and the GCD of the size)
        return (str1 + str2) == (str2 + str1) ?
        str1.substr(0, gcd(size(str1), size(str2))) : "";
    }
};