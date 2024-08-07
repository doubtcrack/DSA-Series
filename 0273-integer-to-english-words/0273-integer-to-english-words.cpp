class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        return intToString(num).substr(1);  // removing the leading space
    }
    
private:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    string intToString(int num) {
        if (num == 0) return "";
        else if (num < 20) return " " + below_20[num];
        else if (num < 100) return " " + tens[num / 10] + intToString(num % 10);
        else if (num < 1000) return " " + below_20[num / 100] + " Hundred" + intToString(num % 100);
        
        for (int i = 1; i < thousands.size(); ++i) {
            if (num < pow(1000, i + 1)) {
                return intToString(num / pow(1000, i)) + " " + thousands[i] + intToString(num % (int)pow(1000, i));
            }
        }
        
        return "";
    }
};