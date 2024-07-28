class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<vector<int>> times(n + 1, vector<int>(2, INT_MAX));
    times[1][0] = 0;

    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty()) {
        auto [current, t] = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            int waitTime = 0;
            if ((t / change) % 2 == 1) {
                waitTime = change - (t % change);
            }
            int newTime = t + waitTime + time;

            if (newTime < times[neighbor][0]) {
                times[neighbor][1] = times[neighbor][0];
                times[neighbor][0] = newTime;
                q.push({neighbor, newTime});
            } else if (newTime > times[neighbor][0] && newTime < times[neighbor][1]) {
                times[neighbor][1] = newTime;
                q.push({neighbor, newTime});
            }
        }
    }

    return times[n][1];
    }
};