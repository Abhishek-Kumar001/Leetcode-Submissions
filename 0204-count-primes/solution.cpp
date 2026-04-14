class Solution {
    void markItsMultiples(int no, int n, vector<int> &primeArr){
        for(int i=no*no; i<n; i+=no){
            primeArr[i] = 1;
        }
    }
public:
    int countPrimes(int n) {
        vector<int> primeArr(n, 0);

        for(int i=2; i*i<n; i++){
            if(primeArr[i] == 0){
                markItsMultiples(i, n, primeArr);
            }
        }

        int cnt = 0;
        for(int i=2; i<n; i++){
            if(primeArr[i] == 0) cnt++;
        }

        return cnt;
    }
};
