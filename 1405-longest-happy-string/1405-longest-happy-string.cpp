class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         // Max heap to always pick the letter with the most remaining count.
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();

            int len = result.size();
            if (len >= 2 && result[len - 1] == char1 && result[len - 2] == char1) {             if (pq.empty()) break;

                auto [count2, char2] = pq.top();
                pq.pop();
                result += char2;
                count2--;
                if (count2 > 0) pq.push({count2, char2});

                pq.push({count1, char1});
            } else {
                result += char1;
                count1--;

                if (count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};