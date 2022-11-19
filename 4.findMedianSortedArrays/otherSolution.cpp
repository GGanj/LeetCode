#include <vector>

class Solution1 {
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

class Solution2 {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            std::vector<int> tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        
        int totalLength = nums1.size() + nums2.size();
        int left1 = 0, right1 = nums1.size(), mid1 = (left1 + right1) / 2;
        int left2 = 0, right2 = nums2.size(), mid2 = (left2 + right2) / 2;
        int passNum = 0;
        while(passNum < totalLength / 2) {

        }


        if(left1 == nums1.size()) {
            if(totalLength % 2 == 1) {

            } else {

            }
        }
        if(left2 == nums2.size()) {
            if(totalLength % 2 == 1) {

            } else {
                
            }
        }
    }
};