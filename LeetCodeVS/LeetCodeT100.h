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

    //22. ��������
    vector<string> t022_generateParenthesis(int n);

    //28. �ҳ��ַ����е�һ��ƥ������±�
    int t028_strStr(string haystack, string needle);

    //29. �������
    int t029_divide(int dividend, int divisor);

    //30. �������е��ʵ��Ӵ�
    vector<int> t030_findSubstring(string s, vector<string>& words);

    //31. ��һ������
    void t031_nextPermutation(vector<int>& nums);

    //32. ���Ч����
    int t032_longestValidParentheses(string s);

    //33. ������ת��������
    int t033_search(vector<int>& nums, int target);

    //33. ������ת��������
    vector<int> t034_searchRange(vector<int>& nums, int target);
    
    //35. ��������λ��
    int t035_searchInsert(vector<int>& nums, int target);

    //36. ��Ч������
    bool t036_isValidSudoku(vector<vector<char>>& board);

    //37. ������
    void t037_solveSudoku(vector<vector<char>>& board);

    //38. �������
    string t038_countAndSay(int n);

    //39. ����ܺ�
    vector<vector<int>> t039_combinationSum(vector<int>& cds, int target);

    //40. ����ܺ� II
    vector<vector<int>> t040_combinationSum2(vector<int>& candidates, int target);

    //41. ȱʧ�ĵ�һ������
    int t041_firstMissingPositive(vector<int>& nums);

    //42. ����ˮ
    int t042_trap(vector<int>& height);

    //43. �ַ������
    string t043_multiply(string num1, string num2);

    //44. ͨ���ƥ��
    bool t044_isMatch(string s, string p);

    //45. ��Ծ��Ϸ II
    int t045_jump(vector<int>& nums);

    //46. ȫ����
    vector<vector<int>> t046_permute(vector<int>& nums);

    //47. ȫ���� II
    vector<vector<int>> t047_permuteUnique(vector<int>& nums);




private:

    //22 ��ȱ�����������
    bool t022_dfs(const string& s, const int& b, int& n, const int& l, const int& r, vector<string>& res);

    //30 ��ȱ�����������
    void dfs_str(string& s, string s_w, int& s_len, vector<string>& words, vector<int>& res, vector<bool>& index);

};
