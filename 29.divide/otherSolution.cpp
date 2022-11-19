#include <climits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) {
            return 0;
        }
        if(dividend == INT_MIN) {
            if(divisor == 1) {
                return INT_MIN;
            }
            if(divisor == -1) {
                return INT_MAX;
            }
        }
        int res = 0 , flag = 1;
        if(dividend > 0) {
            dividend = -dividend;
            flag = !flag;
        }
        if(divisor > 0) {
            divisor = -divisor;
            flag = !flag;
        }
        while(dividend <= divisor) {
            dividend -= divisor;
            ++res;
        }
        if(flag == 0) {
            res = -res;
        }
        return res;
    }
};