class Solution {
public:
    int countPrimes(int n) {
        // apna clg and kunal kushawaha app
        vector<int> marked(n, 0);
        for(int i=2; i*i <n; i++){
            if(marked[i] == 0){
                for(int j=i*i; j<n; j+=i){
                    marked[j] = 1;
                }
            }
        }

        // now we have marked 1 to all non-prime numbers
        int cnt=0;
        for(int i=2; i<n; i++){
            if(marked[i] == 0) cnt++;
        }
        return cnt;
    }
};
