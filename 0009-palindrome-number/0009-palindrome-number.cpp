class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        long revNum = 0, num = x;
        while(num!=0){
            revNum = revNum*10 + num%10;
            num/=10;
        }
        if(revNum == x) return true;
        else return false;
    }
};