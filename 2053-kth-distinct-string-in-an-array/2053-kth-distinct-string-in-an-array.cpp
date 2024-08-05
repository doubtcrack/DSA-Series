class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> countMap;
    for (const auto& str : arr) {
        countMap[str]++;
    }
    int distinctCount = 0;
    for (const auto& str : arr) {
        if (countMap[str] == 1) {
            distinctCount++;
            if (distinctCount == k) {
                return str;
            }
        }
    }
    return "";
    }
};