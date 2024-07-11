class Solution {
public:
    string reverseParentheses(string s) {
    stack<char> stk;
    
    for (char ch : s) {
        if (ch == ')') {
            string temp;
            while (!stk.empty() && stk.top() != '(') {
                temp += stk.top();
                stk.pop();
            }
            // Pop the opening parenthesis '('
            if (!stk.empty()) {
                stk.pop();
            }
            // Push the reversed string back onto the stack
            for (char c : temp) {
                stk.push(c);
            }
        } else {
            stk.push(ch);
        }
    }
    
    string result;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
    }
};