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

    //22. 括号生成
    vector<string> t022_generateParenthesis(int n);

    //28. 找出字符串中第一个匹配项的下标
    int t028_strStr(string haystack, string needle);

    //29. 两数相除
    int t029_divide(int dividend, int divisor);

    //30. 串联所有单词的子串
    vector<int> t030_findSubstring(string s, vector<string>& words);

    //31. 下一个排列
    void t031_nextPermutation(vector<int>& nums);

    //32. 最长有效括号
    int t032_longestValidParentheses(string s);

    //33. 搜索旋转排序数组
    int t033_search(vector<int>& nums, int target);

    //33. 搜索旋转排序数组
    vector<int> t034_searchRange(vector<int>& nums, int target);
    
    //35. 搜索插入位置
    int t035_searchInsert(vector<int>& nums, int target);

private:

    //22 深度遍历辅助函数
    bool t022_dfs(const string& s, const int& b, int& n, const int& l, const int& r, vector<string>& res);

    //30 深度遍历辅助函数
    void dfs_str(string& s, string s_w, int& s_len, vector<string>& words, vector<int>& res, vector<bool>& index);

};
