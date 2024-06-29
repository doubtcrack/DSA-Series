class Solution {
public:
vector<int> topologicalSort(int n, const vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (const auto& neighbors : adj) {
        for (int neighbor : neighbors) {
            indegree[neighbor]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return topoOrder;
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    
    vector<int> topoOrder = topologicalSort(n, adj);
    
    vector<set<int>> ancestors(n);
    for (int node : topoOrder) {
        for (int neighbor : adj[node]) {
            ancestors[neighbor].insert(node);
            for (int ancestor : ancestors[node]) {
                ancestors[neighbor].insert(ancestor);
            }
        }
    }
    
    vector<vector<int>> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
    }
    
    return result;
    }
};