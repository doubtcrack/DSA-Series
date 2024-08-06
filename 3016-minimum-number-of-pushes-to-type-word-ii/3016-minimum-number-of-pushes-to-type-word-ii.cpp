class Solution {
public:
    int minimumPushes(string word) {
    // Step 1: Count the frequency of each letter
    unordered_map<char, int> freqMap;
    for (char c : word) {
        freqMap[c]++;
    }

    // Step 2: Extract frequencies and sort in descending order
    vector<int> frequencies;
    for (auto& entry : freqMap) {
        frequencies.push_back(entry.second);
    }
    sort(frequencies.begin(), frequencies.end(), greater<int>());

    // Step 3: Calculate the minimum pushes needed
    int totalPushes = 0;
    int pushCount = 1;
    int lettersMapped = 0;

    for (int i = 0; i < frequencies.size(); i++) {
        if (i > 0 && i % 8 == 0) {
            pushCount++;
        }
        totalPushes += frequencies[i] * pushCount;
    }

    return totalPushes;
}
};