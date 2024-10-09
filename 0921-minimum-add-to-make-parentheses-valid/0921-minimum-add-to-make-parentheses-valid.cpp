class Solution {
public:
    int minAddToMakeValid(string s) {
         int balance = 0, moves = 0; 

        for (char c : s) {
           c == '(' ? balance++ : ( balance > 0 ? balance-- : moves++);
        }
        return moves + balance;
    }
};