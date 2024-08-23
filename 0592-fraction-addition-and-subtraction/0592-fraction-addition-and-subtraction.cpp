class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int i = 0, len = expression.size();
        
        while (i < len) {
            // Parse the sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '+') ? 1 : -1;
                i++;
            }
            
            // Parse the numerator
            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            
            // Move past the '/'
            i++;
            
            // Parse the denominator
            int denom = 0;
            while (i < len && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }
            
            // Update the fraction using common denominator
            numerator = numerator * denom + sign * num * denominator;
            denominator = denominator * denom;
            
            // Reduce the fraction
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return to_string(numerator) + "/" + to_string(denominator);
    }
};