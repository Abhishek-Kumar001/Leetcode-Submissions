class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(start != 0  || goal != 0){
            int msbOfStart = start & 1;
            int msbOfGoal = goal & 1;

            if(msbOfStart != msbOfGoal) cnt++;

            start = start>>1;
            goal = goal>>1;
        }
        return cnt;
    }
};
