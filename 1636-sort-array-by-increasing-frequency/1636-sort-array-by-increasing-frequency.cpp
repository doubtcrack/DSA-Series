class Solution {
public:

    // Custom comparator function
    bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
        // First, compare by frequency (increasing order)
        if (a.second != b.second) {
            return a.second < b.second;
        }
        // If frequencies are the same, compare by value (decreasing order)
        return a.first > b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
    // Step 1: Count the frequency of each element
    unordered_map<int, int> frequency;
    for (int num : nums) {
        frequency[num]++;
    }

    // Step 2: Create a vector of pairs (element, frequency)
    vector<pair<int, int>> elements;
    for (const auto& entry : frequency) {
        elements.push_back(entry);
    }

    // Step 3: Sort the vector using the custom comparator
    sort(elements.begin(), elements.end(), customCompare);

    // Step 4: Construct the sorted array based on frequency
    vector<int> sortedArray;
    for (const auto& element : elements) {
        sortedArray.insert(sortedArray.end(), element.second, element.first);
    }

    return sortedArray;
    }
};