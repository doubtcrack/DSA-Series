class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int i = 0;  // Pointer to traverse from the start
        int j = 0;  // Pointer to traverse from the end
        
        // Traverse from the beginning while the words match
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }
        
        // Traverse from the end while the words match
        while (j < words1.size() - i && j < words2.size() - i && 
               words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }
        
        // Check if all words match between i and j
        return i + j == min(words1.size(), words2.size());
    }
    
    // Utility function to split a sentence into words
    vector<string> split(const string& sentence) {
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
