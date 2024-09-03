class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for(auto c:s){
        str += to_string(c-'a'+1);
        }
        while (k > 0) {
            int sum = 0;
            for (char c : str) {
                sum += c - '0'; 
            }
            str = to_string(sum);
            k--;
        }
        return stoi(str);
    }
};