class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    vector<string> result;

    auto updateWordCount = [&wordCount](const string& sentence) {
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            wordCount[word]++;
        }
    };

    updateWordCount(s1);
    updateWordCount(s2);

    for (const auto& entry : wordCount) {
        if (entry.second == 1) { 
            result.push_back(entry.first);
        }
    }

    return result;
    }
};