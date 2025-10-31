class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int* frequencyArr = new int[n](); // () initializes all elements to 0

        for(int x : nums) frequencyArr[x]++;

        vector<int> ansArr;
        for(int i=0; i<n; i++){
            if(frequencyArr[i] == 2) ansArr.push_back(i);
        }

        return ansArr;
    }
};
