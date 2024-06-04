class Solution {
public:
    int longestPalindrome(string s) {
    map<char, int> mp; 
    for(int i = 0; i < s.length(); i++) mp[s[i]]++;

    int length = 0;
    bool odd = false;

    for(auto it : mp) {
        if(it.second % 2 == 0) {
            length += it.second;
        } else {
            length += it.second - 1; 
            odd = true;
        }
    }


    return odd ? length+1 : length;
}
};