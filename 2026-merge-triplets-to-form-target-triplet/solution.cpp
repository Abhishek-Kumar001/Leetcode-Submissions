class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int targetX = target[0];
        int targetY = target[1];
        int targetZ = target[2];
        bool x = false, y = false, z = false;

        for (int i = 0; i < triplets.size(); i++) {
            // Skip triplets that overshoot target on any coordinate — unusable
            if (triplets[i][0] > targetX || triplets[i][1] > targetY || triplets[i][2] > targetZ)
                continue;

            if (triplets[i][0] == targetX) x = true;
            if (triplets[i][1] == targetY) y = true;
            if (triplets[i][2] == targetZ) z = true;

            if (x && y && z) return true;
        }

        return false;
    }
};
