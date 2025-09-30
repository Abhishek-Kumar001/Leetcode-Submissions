class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frequency(101, 0);

        for(int x: nums){
            frequency[x]++;
        }

        int maxFreq = 0;
        int freqCount = 0;
        for(int i=1; i<=100; i++){
            if(frequency[i] == maxFreq) freqCount+=frequency[i];
            else if(frequency[i] > maxFreq){
                maxFreq = frequency[i];
                freqCount = frequency[i];
            } 
        }
        return freqCount;
    }
};
