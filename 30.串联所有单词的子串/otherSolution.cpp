#include <vector>
#include <string>
#include <iostream>
class Solution {
public:
    std::vector<int> res = {};
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int wordLength = words[0].length();
        isMatch(s, 0, words, wordLength);
        return res;
    }

    void isMatch(std::string s, int indexS, std::vector<std::string>& words, const int& wordLength, int beginIndex = -1) {
        if((s.length() - indexS) < (wordLength * words.size())) {
            return;
        }
        if(words.size() == 0 && beginIndex != -1) {
            if(res.size() == 0 || *(res.end() - 1) != beginIndex) {
                res.push_back(beginIndex);
            }
            return;
        } 
        std::vector<std::string>::iterator strIter = words.begin();
        while(strIter != words.end()) {
            if(s[indexS] == (*strIter)[0]) {
                // compare string
                if(s.compare(indexS, wordLength, *strIter) == 0) {
                    std::string word = *strIter;
                    strIter = words.erase(strIter);
                    isMatch(s, indexS + wordLength, words, wordLength, (beginIndex == -1) ? indexS : beginIndex);
                    strIter = words.insert(strIter, word);                        
                }
            }
            ++strIter;
        }
        if(beginIndex == -1) {
            isMatch(s, indexS + 1, words, wordLength);
        }
    }
};