class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> people;
    int n = names.size();
    
    for (int i = 0; i < n; ++i) {
        people.push_back({heights[i], names[i]});
    }
    
    sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    });
    
    vector<string> sortedNames;
    for (const auto& person : people) {
        sortedNames.push_back(person.second);
    }
    
    return sortedNames;
    }
};