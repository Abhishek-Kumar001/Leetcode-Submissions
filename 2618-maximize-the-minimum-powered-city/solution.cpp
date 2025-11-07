class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        // 1) Base power via prefix sums: power[i] = sum(stations[L..R]), L=max(0,i-r), R=min(n-1,i+r)
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + (long long)stations[i];

        auto basePowerAt = [&](int i) -> long long {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            return prefix[R + 1] - prefix[L];
        };

        vector<long long> base(n);
        long long maxBase = 0;
        for (int i = 0; i < n; ++i) {
            base[i] = basePowerAt(i);
            if (base[i] > maxBase) maxBase = base[i];
        }

        // 2) Binary search the answer
        long long lo = 0, hi = maxBase + k, ans = 0;

        auto can = [&](long long X) -> bool {
            long long rem = k;
            // add[i] is a difference array over cities (NOT stations):
            // when we add `need` at city i, it increases power for cities in [i, i+2r]
            vector<long long> add(n + 1, 0);
            long long extra = 0;

            for (int i = 0; i < n; ++i) {
                extra += add[i];                 // current accumulated added power affecting city i
                long long curr = base[i] + extra;

                if (curr < X) {
                    long long need = X - curr;
                    if (need > rem) return false;
                    rem -= need;

                    // Greedily place at pos = min(n-1, i + r).
                    // Its effect on cities (in sweep indices) is from i to end = min(n-1, i + 2r).
                    extra += need;                          // starts affecting from i immediately
                    int end = min(n - 1, i + 2 * r);
                    if (end + 1 < n) add[end + 1] -= need;  // stop effect after 'end'
                }
            }
            return true;
        };

        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

