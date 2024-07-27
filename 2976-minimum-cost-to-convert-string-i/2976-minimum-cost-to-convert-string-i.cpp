class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int n = 26; // number of lowercase English letters
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize the distance of each character to itself as 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Populate the initial distances based on the transformation rules
    for (int i = 0; i < original.size(); ++i) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        dist[from][to] = min(dist[from][to], cost[i]);
    }

    // Apply Floyd-Warshall algorithm to find the shortest path between all pairs of nodes
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Calculate the total minimum cost to convert the source string to the target string
    int totalCost = 0;
    for (int i = 0; i < source.length(); ++i) {
        int from = source[i] - 'a';
        int to = target[i] - 'a';
        if (dist[from][to] == INT_MAX) {
            return -1; // Impossible to convert source[i] to target[i]
        }
        totalCost += dist[from][to];
    }

    return totalCost;
    }
};