class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int LeaseBeamInPrevRow, ans = 0;
        for(int i=0; i<n; i++){
            int LeaserBeamInCurrRow = 0;
            for(int j=0; j<m; j++){
                if(bank[i][j] == '1'){
                   ans+=LeaseBeamInPrevRow;
                   LeaserBeamInCurrRow++;
                }
            }
            LeaseBeamInPrevRow = LeaserBeamInCurrRow ? LeaserBeamInCurrRow :    LeaseBeamInPrevRow;
        }
        return ans;
    }
};
