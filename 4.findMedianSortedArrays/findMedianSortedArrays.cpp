/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.34%)
 * Likes:    5364
 * Dislikes: 0
 * Total Accepted:    692.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

#include <vector>
// @lc code=start

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
        std::vector<double> myVector;
        while(iter1 != nums1.end() || iter2 != nums2.end()) {
            if(iter1 == nums1.end()) {
                myVector.push_back(*iter2);
                iter2++;
                continue;
            }
            if(iter2 == nums2.end()) {
                myVector.push_back(*iter1);
                iter1++;
                continue;
            }
            if(*iter1 == *iter2) {
                myVector.push_back(*iter1);
                myVector.push_back(*iter2);
                iter1++;
                iter2++;
                continue;
            }
            if(*iter1 > *iter2) {
                myVector.push_back(*iter2);
                iter2++;
                continue;
            }
            if(*iter1 < *iter2) {
                myVector.push_back(*iter1);
                iter1++;
                continue;
            }
        }
        int length = myVector.size();
        if( length % 2 == 1) {
            return myVector[length / 2 ];
        }
        return (myVector[length / 2 - 1] + myVector[length / 2]) / 2;
    }
};
// @lc code=end

