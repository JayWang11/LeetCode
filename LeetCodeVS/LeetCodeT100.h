#pragma once

#include"tool.h"

using namespace std;


class Solution_LeetCodeT100
{
public:

    vector<int> t001_twoSum(vector<int>& nums, int target);
    //ListNode* t002_addTwoNumbers(ListNode* l1, ListNode* l2);
    double t004_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    string t005_longestPalindrome(string s);
    // 6. N 字形变换
    string t006_convert(string s, int numRows);
    // 10. 正则表达式匹配
    bool t010_isMatch(string s, string p);

    // 15. 三数之和
    vector<vector<int>> t015_threeSum(vector<int>& nums);
    // 18. 四数之和
    vector<vector<int>> t018_fourSum_iterator(vector<int>& nums, int target); //迭代器版本
    vector<vector<int>> t018_fourSum(vector<int>& nums, int target); //下标版本
    // 20. 有效的括号
    bool t020_isValid(string s);
private:
};
