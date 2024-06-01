class Solution {
public:
    int reverse(int x) {
    int reversedNumber = 0;
    
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow before actually performing the operation
        if (reversedNumber > INT_MAX/10 || (reversedNumber == INT_MAX / 10 && pop > 7)) {
            return 0;
        }
        if (reversedNumber < INT_MIN/10 || (reversedNumber == INT_MIN / 10 && pop < -8)) {
            return 0;
        }
        
        reversedNumber = reversedNumber * 10 + pop;
    }
    
    return reversedNumber;
}
};