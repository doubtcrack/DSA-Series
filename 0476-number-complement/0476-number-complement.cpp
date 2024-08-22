class Solution {
public:
    int findComplement(int num) {
        // Step 1: Find the number of bits
        int bitLength = 0;
        int temp = num;
        while (temp > 0) {
            bitLength++;
            temp >>= 1;  // work as a divider of 2
        }
        
        // Step 2: Create a mask with all bits set to 1 (of the same length as num)
     int mask = (1U << bitLength) - 1;   //(1 << bitLength) works as 2 ki power bitlength 
        // BTS it works this way: 1<<3 == 0001 => 1000 : it shifted one to three steps left
        
        // Step 3: XOR the number with the mask to flip all bits
        return num ^ mask;
    }
};