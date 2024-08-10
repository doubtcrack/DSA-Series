class Solution {
public:
    class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

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
};

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    UnionFind uf(n * n * 4);

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int base = (r * n + c) * 4;
            char ch = grid[r][c];
            
            // Connect triangles within the same cell
            if (ch == '/') {
                uf.unite(base + 0, base + 3);
                uf.unite(base + 1, base + 2);
            } else if (ch == '\\') {
                uf.unite(base + 0, base + 1);
                uf.unite(base + 2, base + 3);
            } else {  // ' ' connects all 4 parts
                uf.unite(base + 0, base + 1);
                uf.unite(base + 1, base + 2);
                uf.unite(base + 2, base + 3);
            }

            // Connect triangles between adjacent cells
            if (r < n - 1) {  // Connect to the cell below
                uf.unite(base + 2, base + 4 * n);
            }
            if (c < n - 1) {  // Connect to the cell to the right
                uf.unite(base + 1, base + 7);
            }
        }
    }

    int regions = 0;
    for (int i = 0; i < n * n * 4; ++i) {
        if (uf.find(i) == i) {
            regions++;
        }
    }

    return regions;
}
};