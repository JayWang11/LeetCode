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
    // 6. N ���α任
    string t006_convert(string s, int numRows);
    // 10. ������ʽƥ��
    bool t010_isMatch(string s, string p);

    // 15. ����֮��
    vector<vector<int>> t015_threeSum(vector<int>& nums);
    // 18. ����֮��
    vector<vector<int>> t018_fourSum_iterator(vector<int>& nums, int target); //�������汾
    vector<vector<int>> t018_fourSum(vector<int>& nums, int target); //�±�汾
    // 20. ��Ч������
    bool t020_isValid(string s);
private:
};
