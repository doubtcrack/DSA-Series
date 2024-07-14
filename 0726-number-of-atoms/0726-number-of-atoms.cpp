class Solution {

private:
    map<string, int> parseFormula(const string& formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                st.push(map<string, int>());
                ++i;
            } else if (formula[i] == ')') {
                map<string, int> top = st.top();
                st.pop();
                ++i;
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + formula[i] - '0';
                    ++i;
                }
                if (count == 0) count = 1;
                for (auto& [element, cnt] : top) {
                    st.top()[element] += cnt * count;
                }
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) ++i;
                string element = formula.substr(start, i - start);
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + formula[i] - '0';
                    ++i;
                }
                if (count == 0) count = 1;
                st.top()[element] += count;
            }
        }
        return st.top();
    }

public:
    string countOfAtoms(string formula) {
        map<string, int> counts = parseFormula(formula);
        string result;
        for (const auto& element : counts) {
            result += element.first;
            if (element.second > 1) {
                result += to_string(element.second);
            }
        }
        return result;
    }
};