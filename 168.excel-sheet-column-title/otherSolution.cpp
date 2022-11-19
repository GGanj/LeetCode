#include <string>

class Solution1 {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res = "";
        while(columnNumber != 0) {
            int tmp = columnNumber % 26;
            columnNumber /= 26;
            if(tmp == 0) {
                tmp = 26;
                --columnNumber;
            }                        
            res = (char)(tmp + 64)+ res;
        }
        return res;
    }
};

class Solution2 {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res = "";
        while(columnNumber != 0) {
            --columnNumber;
            int tmp = columnNumber % 26;
            columnNumber /= 26;                    
            res = (char)(tmp + 'A')+ res;
        }
        return res;
    }
};