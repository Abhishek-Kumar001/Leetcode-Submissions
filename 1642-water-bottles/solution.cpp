class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totelBottleYouCanDrink = numBottles;

        while( numBottles >= numExchange ){
            totelBottleYouCanDrink += (numBottles / numExchange);
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        return totelBottleYouCanDrink;
    }
};
