class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;  // To handle edge cases like INT_MIN
        if (n == 0)
            return 1;
        else if (n < 0){
            x = 1/x;
            exp *= -1;
        }
        double result = 1;
        while(exp > 0){
            if (exp % 2 != 0){
                result *= x;
            }
            x *= x;
            exp /= 2;
        }
        return result;
    }
};
