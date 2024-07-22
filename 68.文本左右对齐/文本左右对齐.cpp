/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode.cn/problems/text-justification/description/
 *
 * algorithms
 * Hard (53.57%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 133.8K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth
 * 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 注意:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: words = ["This", "is", "an", "example", "of", "text", "justification."],
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入:words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth
 * = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] 由小写英文字母和符号组成
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int rowLen = 0;
        vector<string> ret;
        int pLeft = 0, pRight = 0;
        string rowStr;
        while(pRight < words.size()) {
            if(rowLen + words[pRight].size() < maxWidth - pRight + pLeft + 1) {
                rowLen += words[pRight].size();
                ++pRight;
            // } else if (rowLen + words[pRight].size() == maxWidth) {
            //     while(pLeft <= pRight) {
            //         rowStr.append(words[pLeft]);
            //         ++pLeft;
            //     }
            //     ret.push_back(rowStr);
            //     ++pLeft;
            //     ++pRight;
            //     rowLen = 0;
            //     rowStr.clear();
            } else {
                int interval = maxWidth - rowLen;
                int wordsNum = pRight - pLeft;
                // while(interval < wordsNum - 1) {
                //     interval += words[--pRight].size();
                //     --wordsNum;
                // }
                if(wordsNum <= 2) {
                    rowStr.append(words[pLeft]);
                    rowStr.append(std::string(interval, ' '));
                    if(wordsNum == 2) {
                        rowStr.append(words[++pLeft]);
                    }
                    ret.push_back(rowStr);
                    ++pLeft;
                    rowLen = 0;
                    rowStr.clear();
                } else {
                    int x = interval / (wordsNum - 1);
                    int y = interval % (wordsNum - 1);
                    while(pLeft < pRight) {
                        rowStr.append(words[pLeft++]);
                        if(wordsNum > 1) {
                            rowStr.append(std::string(x, ' '));
                            --wordsNum;
                        }
                        if(y > 0) {
                            rowStr.append(1, ' ');
                            --y;
                        }
                    }
                    ret.push_back(rowStr);
                    rowLen = 0;
                    rowStr.clear();
                }
            }
        }

        if(rowLen > 0) {
            while(pLeft < words.size()) {
                rowStr.append(words[pLeft++]);
                rowStr.append(std::string(1, ' '));
                ++rowLen;
            }
            if(rowLen > maxWidth) {
                rowStr.pop_back();
            } else {
                rowStr.append(std::string(maxWidth - rowLen, ' '));
            }
            ret.push_back(rowStr);
        }

        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    // vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    // vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    // vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};


    int maxWidth = 16;
    vector<string> ret = s.fullJustify(words, maxWidth);
    for(int i = 0; i < ret.size(); ++i) {
        std::cout << ret[i].c_str();
        std::cout << std::endl;
    }
    return 1;
}

