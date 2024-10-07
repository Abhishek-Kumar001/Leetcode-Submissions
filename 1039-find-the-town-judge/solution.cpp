class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n + 1, 0);
        vector<int> inDegree(n + 1, 0);

        int potentialJudge = 1;
        for (auto it : trust) {
            int u = it[0];
            int v = it[1];

            outDegree[u]++;
            inDegree[v]++;

            // since u is pointing to v so u can't be ans but v can be
            //  potential judge. YOU CAN ALSO CHECK OUTSIDE ALSO
            if (outDegree[v] == 0 && inDegree[v] == n - 1)
                potentialJudge = v;
        };

        if (outDegree[potentialJudge] == 0 && inDegree[potentialJudge] == n - 1)
            return potentialJudge;


        // HAMNE UPAR HI CHECK KAR LIYA HAI
        // for(int i=1; i<=n; i++){
        //    if(outDegree[i] == 0 && inDegree[i] == n-1) return i;
        // }

        return -1;
    }
};
