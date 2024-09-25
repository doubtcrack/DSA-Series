
class TrieNode {
 public:
    unordered_map<char, TrieNode*> children; 
    int count = 0;  
    TrieNode() = default; 
};

class Trie {
 public:
    TrieNode* root; 

    Trie() {
        root = new TrieNode(); 
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            // If the character doesn't exist in children, create a new TrieNode
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];  
            node->count++; 
        }
    }
    int getScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c]; 
            score += node->count; 
        }
        return score;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> result;

        // Calculate the prefix score for each word and store it in the result
        for (const string& word : words) {
            result.push_back(trie.getScore(word));
        }

        return result;
    }
};
