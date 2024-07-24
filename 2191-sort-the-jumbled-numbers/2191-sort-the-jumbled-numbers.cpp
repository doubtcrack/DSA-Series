class Solution {
public:
 // Function to get the mapped value of an integer
int getMappedValue(int num, const vector<int>& mapping) {
    string numStr = to_string(num);
    string mappedStr;
    for (char ch : numStr) {
        mappedStr += to_string(mapping[ch - '0']);
    }
    return stoi(mappedStr);
}

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
   // Create a map to store the original and mapped values
    vector<pair<int, int>> mappedNums;
    for (int num : nums) {
        int mappedValue = getMappedValue(num, mapping);
        mappedNums.emplace_back(mappedValue, num);
    }

    // Sort the mapped values, but maintain the relative order of equal mapped values
    stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    // Extract the sorted original values
    vector<int> sortedNums;
    for (const auto& p : mappedNums) {
        sortedNums.push_back(p.second);
    }

    return sortedNums;
}
};