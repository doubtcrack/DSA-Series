class Solution {
public:
 vector<int> parent;
    vector<int> rank;
    
    // Find the root of a node with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initially, every stone is its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Connect stones that are in the same row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }
        
        // Find the number of connected components
        unordered_set<int> uniqueComponents;
        for (int i = 0; i < n; ++i) {
            uniqueComponents.insert(find(i));
        }
        
        // The number of stones that can be removed
        return n - uniqueComponents.size(); }
};