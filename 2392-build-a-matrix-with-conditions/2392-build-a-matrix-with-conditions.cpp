class Solution {
public:

vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
    vector<int> inDegree(k + 1, 0);
    unordered_map<int, unordered_set<int>> graph;

    for (auto& condition : conditions) {
        int u = condition[0], v = condition[1];
        if (graph[u].insert(v).second) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        for (int neighbor : graph[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return topoOrder.size() == k ? topoOrder : vector<int>();
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // return order of rows
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        for(auto item: rowOrder){
             cout<<item<<" ";
        }
        cout<<"\n";
        
         // return order of cols
    vector<int> colOrder = topologicalSort(k, colConditions);
    for(auto item: colOrder){
             cout<<item<<" ";
        }

    if (rowOrder.empty() || colOrder.empty()) {
        return {}; // Return an empty matrix if there's no valid order
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    unordered_map<int, int> rowIndex, colIndex;

    for (int i = 0; i < k; ++i) {
        rowIndex[rowOrder[i]] = i;
        colIndex[colOrder[i]] = i;
    }

    for (int num = 1; num <= k; ++num) {
        matrix[rowIndex[num]][colIndex[num]] = num;
    }

    return matrix;
    }
};