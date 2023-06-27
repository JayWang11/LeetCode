#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stack>
#include<set>
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
    // 15. ����֮��
    vector<vector<int>> t015_threeSum(vector<int>& nums);
    // 18. ����֮��
    vector<vector<int>> t018_fourSum_iterator(vector<int>& nums, int target); //�������汾
    vector<vector<int>> t018_fourSum(vector<int>& nums, int target); //�±�汾
    // 20. ��Ч������
    bool t020_isValid(string s);
private:
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};