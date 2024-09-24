class Solution {
public:

// ------------------ method 1 --------------------- //


//     int commonPrefixLength(int a, int b) {
//     string strA = to_string(a);
//     string strB = to_string(b);
    
//     int len = 0;
//     while (len < strA.size() && len < strB.size() && strA[len] == strB[len]) {
//         len++;
//     }
//     return len;
// }

// int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//     int maxLength = 0;

//     for (int x : arr1) {
//         for (int y : arr2) {
//             maxLength = max(maxLength, commonPrefixLength(x, y));
//         }
//     }
//     return maxLength;
// }

// ---------------------- method 2 --------------------- //

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefixMap;
        
        // Step 1: Build the prefix map for arr1
        for (int num : arr1) {
            string strNum = to_string(num);
            string prefix = "";
            for (char ch : strNum) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }
        
        int maxLength = 0;
        
        // Step 2: Check for common prefixes in arr2
        for (int num : arr2) {
            string strNum = to_string(num);
            string prefix = "";
            for (char ch : strNum) {
                prefix += ch;
                if (prefixMap.find(prefix) != prefixMap.end()) {
                    maxLength = max(maxLength, static_cast<int>(prefix.length()));
                }
            }
        }
        
        return maxLength;
    }
};