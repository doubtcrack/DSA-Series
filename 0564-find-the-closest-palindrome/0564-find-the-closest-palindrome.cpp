class Solution {
public:
    string nearestPalindromic(string n) {
         int len = n.size();
        vector<long long> candidates;

        // Edge cases: 100...001 or 999...999
        candidates.push_back(pow(10, len - 1) - 1);  // e.g., 999 for 1000
        candidates.push_back(pow(10, len) + 1);      // e.g., 10001 for 9999

        // Get the prefix and make three candidates
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (long long i = -1; i <= 1; ++i) {
            string candidate = to_string(prefix + i);
            string mirrored = candidate + string(candidate.rbegin() + (len % 2), candidate.rend());
            candidates.push_back(stoll(mirrored));
        }

        long long minDiff = LLONG_MAX, original = stoll(n), closest = 0;
        for (long long candidate : candidates) {
            if (candidate == original) continue;
            long long diff = abs(candidate - original);
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                minDiff = diff;
                closest = candidate;
            }
        }

        return to_string(closest);

    }
};