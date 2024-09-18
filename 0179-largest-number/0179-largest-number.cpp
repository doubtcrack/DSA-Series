class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

        // Edge case: when the largest number is 0 (e.g., [0, 0])
        if (strNums[0] == "0") {
            return "0";
        }

        // Join sorted numbers to form the largest number
        string largestNum;
        for (string& num : strNums) {
            largestNum += num;
        }

        return largestNum;
    }
};