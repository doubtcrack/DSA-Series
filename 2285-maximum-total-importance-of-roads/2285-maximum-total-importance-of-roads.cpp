class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> connections(n, 0);
    for (const auto& road : roads) {
        connections[road[0]]++;
        connections[road[1]]++;
    }
    
    vector<pair<int, int>> cities;
    for (int i = 0; i < n; ++i) {
        cities.push_back({connections[i], i});
    }
    
    sort(cities.rbegin(), cities.rend());
    unordered_map<int, int> valueMap;

    int value = n;
    for (const auto& city : cities) {
        valueMap[city.second] = value--;
    }
    
    long long totalImportance = 0;
    for (const auto& road : roads) {
        totalImportance += valueMap[road[0]] + valueMap[road[1]];
    }
    
    return totalImportance;
    }
};
