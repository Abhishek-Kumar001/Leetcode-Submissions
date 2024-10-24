class Solution {
    public int repeatedStringMatch(String a, String b) {
        int n = a.length(), m = b.length();

        if (a.contains(b))
            return 1;

        String originalAString = a;
        int times = 1;
        while (n <= m) {
            a += originalAString;
            times++;
            if (a.contains(b))
                return times;
            n = a.length();
        }

        a += originalAString;
        times++;
        if (a.contains(b))
            return times;

        return -1;
    }
}
