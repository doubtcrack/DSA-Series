class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        /* First Method */

        // long revNum = 0, num = x;
        // while(num!=0){
        //     revNum = revNum*10 + num%10;
        //     num/=10;
        // }
        // if(revNum == x) return true;
        // else return false;

        /* Second Method (String) */

        string str = to_string(x);
        int i = 0, j=str.length()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};