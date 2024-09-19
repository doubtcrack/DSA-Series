class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> result;
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            if (c == '+' || c == '-' || c == '*') {
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);

                vector<int> left = diffWaysToCompute(leftPart);
                vector<int> right = diffWaysToCompute(rightPart);

                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        memo[expression] = result;
        return result;
    }
};
