class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int removedCount = 0;
        // int prevStart = intervals[0][0];  // no need of it b/c not getting use anyware
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end   = intervals[i][1];

            if (start < prevEnd) {
                // Overlap: remove the interval with the larger end,
                // keep the tighter one to leave more room for future intervals.
                removedCount++;
                prevEnd = min(prevEnd, end);
            } else {
                // No overlap: this interval becomes the new reference.

                // prevStart = start; //  not needed
                prevEnd = end;
            }
        }

        return removedCount;
    }
};
