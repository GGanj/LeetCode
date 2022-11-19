#include <string>
#include <vector>
#include <stack>

class Solution1 {
public:
    bool isValid(std::string s) {
        if(s.size() % 2 == 1) {
            return false;
        }
        std::string::iterator iter;
        std::vector<char> stack;
        for(iter = s.begin(); iter < s.end(); ++iter) {
            if(*iter == '(' || *iter == '[' || *iter == '{') {
                stack.push_back(*iter);
                continue;
            }
            if(stack.size() > 0
                && (*iter == ')' && *(stack.end() - 1) == '(')
                || (*iter == ']' && *(stack.end() - 1) == '[')
                || (*iter == '}' && *(stack.end() -1) == '{')
            ) {
                stack.pop_back();
                continue;
            }
            return false;
        }
        if(stack.size() == 0) {
            return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isValid(std::string s) {
        if(s.size() % 2 == 1) {
            return false;
        }
        std::string::iterator iter;
        std::stack<char> stack;
        for(iter = s.begin(); iter < s.end(); ++iter) {
            if(*iter == '(' || *iter == '[' || *iter == '{') {
                stack.push(*iter);
                continue;
            }
            if(stack.size() > 0
                && ((*iter == ')' && stack.top() == '(')
                || (*iter == ']' && stack.top() == '[')
                || (*iter == '}' && stack.top() == '{'))
            ) {
                stack.pop();
                continue;
            }
            return false;
        }
        if(stack.size() == 0) {
            return true;
        }
        return false;
    }
};