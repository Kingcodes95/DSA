class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // if n == 0 then there is no plants to be placed
        if (n == 0) {
            return true;
        }

        for (int i = 0; i < flowerbed.size(); i++) {
            // flowerbed[i] == 0 then we might be able to place a flower here
            // AND
            // i == 0 || flowerbed[i-1], either i is 0 OR flowerbed[i-1] (previous value needs to be checked for 0) if its 1 then we cannot add the flower.
            // AND
            // i == flowerbed.size() -1 || flowerbed[i+1] == 0, this checks if i is the last position in the array or if its empty, if it's not the last value
            // then it will check the right value for 0. 
            // if all of these pass then a plant is plantable.
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                // if the flower bed fits all the parameters, then that i value can now be placed as a 1
                flowerbed[i] = 1;

                // then minus 1 value of n because we just placed it.
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};