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
private:

    //22 深度遍历辅助函数
    bool t022_dfs(const string& s, const int& b, int& n, const int& l, const int& r, vector<string>& res);



};
