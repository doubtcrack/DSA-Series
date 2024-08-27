class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
         // Step 1: Create an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Step 2: Priority queue to keep track of maximum probability (max-heap)
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        // Step 3: Dijkstra's algorithm to find the maximum probability path
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) {
                return prob;
            }

            // Explore neighbors
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        // If no path is found to the end
        return 0.0;
    }
};