#include"LeetCodeT100.h"
using namespace std;

/** t001：
给定一个整数数组 nums??和一个整数目标值 target，请你在该数组中找出 和为目标值 target?? 的那??两个??整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<int>  Solution_LeetCodeT100::t001_twoSum(vector<int>&nums, int target) {

    vector<int> r[2];
    int i ,j=0;
    for( i=0;i<nums.size();i++){       
        for( j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }
    return {i,j};
}

/** t002
 * 给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照??逆序??的方式存储的，并且每个节点只能存储一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0??开头。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//ListNode* Solution_LeetCodeT100::t002_addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    int val_1 = 0;
//    int val_2 = 0;
//    int sum = 0;
//    int carry = 0;
//    int l1_len = 0;
//    int l2_len = 0;
//    ListNode* p1_s = l1;
//    ListNode* p2_s = l2;
//    ListNode* p_e = l1;
//    while (/* condition */l1 || l2)
//    {
//        /* code */
//        val_1 = l1 != nullptr ? l1->val : 0;
//        val_2 = l2 != nullptr ? l2->val : 0;
//        sum = val_1 + val_2 + carry;
//        carry = sum > 9 ? 1 : 0;
//        sum = sum % 10;
//
//        if (l1) {
//            l1->val = sum;
//            p_e = l1;
//            l1 = l1->next;
//            l1_len += 1;
//        }
//        if (l2) {
//            l2->val = sum;
//            p_e = l2;
//            l2 = l2->next;
//            l2_len += 1;
//        }
//    }
//    if (carry) {
//        p_e->next = new ListNode(carry);
//    }
//    if (l1_len > l2_len)
//        return p1_s;
//
//    else
//        return p2_s;
//}

/**
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组??nums1 和??nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

double Solution_LeetCodeT100::t004_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    // 普通解法， 时间复杂度还是O（m+n） ，要继续优化 考虑二分法

    int numsLong = nums1.size() + nums2.size();
    int flag = 1;
    if (numsLong % 2 == 0) {
        flag = 2;
    }
    int n1 = 0, n2 = 0;
    double mid1 = 0, mid2 = 0;
    for (int i = 0; i <= numsLong / 2; i++) {
        mid1 = mid2;
        // 达到 数组 1， 2 的边界，便直接跳过
        if (n1 == nums1.size()) {
            mid2 = nums2[n2];
            n2 += 1;
        }
        else if (n2 == nums2.size()) {
            mid2 = nums1[n1];
            n1 += 1;
        }
        else if (nums1[n1] <= nums2[n2]) {
            mid2 = nums1[n1];
            n1 += 1;
        }
        else if (nums1[n1] > nums2[n2]) {
            mid2 = nums2[n2];
            n2 += 1;
        }

    }
    if (flag == 1) {
        mid1 = 0;
    }

    // return double(numsLong);
    return (mid1 + mid2) / flag * 1.0;

}


/**
 5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
*/
string Solution_LeetCodeT100::t005_longestPalindrome(string s)
{
    // 中心扩展算法
    int left;
    int right;
    int index_1;
    int index_2;
    int start = 0;
    int l = 1;
    if (s.size() == 1)
        return s;
    if (s[0] == s[1])
        l = 2;
    // 遍历所有字符 
    for (int i = 1; i < s.size(); i++) {
        left = 0;
        right = 1;
        index_1 = 1;
        index_2 = 1;
        //单偶数回文检测统一
        while (i - left >= 0 && i + right < s.size() && (index_1 || index_2)) {
            if (s[i - left] == s[i + right] && index_2) {
                if (right + left + 1 > l) {
                    start = i - left;
                    l = right + left + 1;
                }
                // cout << "start 2 : "<< start <<endl;
                // cout << "l 2 : "<< l <<endl;
            }
            else
                index_2 = 0;
            if (i - left - 1 >= 0 && index_1) {
                if (s[i - left - 1] == s[i + right]) {
                    if (left + right + 2 > l) {
                        start = i - left - 1;
                        l = left + right + 2;
                    }
                    // cout << "start 1 : "<< start <<endl;
                    // cout << "l 1 : "<< l <<endl;
                }
                else
                    index_1 = 0;
            }
            else
                index_1 = 0;
            right++;
            left++;
        }

    }
    // cout << "start : "<< start <<endl;
    // cout << "l : "<< l <<endl;
    return s.substr(start, l);
}

/**
 * 6. N 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行??Z 字形排列。
比如输入字符串为 "PAYPALISHIRING"??行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
*/
string Solution_LeetCodeT100::t006_convert(string s, int numRows = 3)
{
    int Long = s.size();
    if (numRows == 1 || numRows >= Long)
        return s;
    string *n_s = new string[numRows];  // 动态内存分配解决形参不能作为常量值定义数组长度问题
    string newS;
    int flag = 1;
    int n = 0;
    for (char& c : s) {
        n_s[n] += c;
        n += flag;
        if (n == 0 || n == numRows - 1) {
            flag = flag * -1;
        }
    }
    n = 0;
    // cout << " n :" << n << endl;
    while (n < numRows) {
        newS += n_s[n];
        n++;
    }
    return newS;
}

//
/*15. 三数之和
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> Solution_LeetCodeT100::t015_threeSum(vector<int>& nums)
{
    // 二重循环和三重循环用双指针处理，把O(n^3) 降为 O(n^2)
    //vector<int>::iterator i = find(test.begin(), test.end(), 1);  find函數，左闭右开
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if ((*nums.begin() >= 0 && *(nums.end() - 1) > 0) || (*(nums.end() - 1) <= 0) && *nums.begin() < 0) return res;
    if (*(nums.end() - 1) == 0 && *nums.begin() == 0) return { {0,0,0} };
    vector<int>::iterator it = nums.begin();
    vector<int>::reverse_iterator right = nums.rbegin(); //右边界，牺牲空间换取执行速度
    while (*it <= 0 && *right >= 0) {
        if (it != nums.begin() && *(it - 1) == *it) { it++; continue; }  // 去重复
        if ((*right) * 2 < -*it) {
            it++;
            continue;
        }
        if (-(*it) * 2 < *right) {
            right++;
            continue;
        }
        vector<int>::reverse_iterator rit = right;
        vector<int>::iterator left = it + 1;
        while (left < (rit + 1).base()) {
            if (rit != nums.rbegin() && *(rit - 1) == *rit) { rit++; continue; } // 去重复
            if (left != it + 1 && *(left - 1) == *left) { left++; continue; } // 去重复
            if (*left + *rit == -*it) {
                res.push_back({ *it, *left,*rit });
                rit++, left++;
            }
            else  if (*left + *rit > -*it) rit++;
            else left++;
        }
        it++;
    }
    return res;
}



/*18. 四数之和
* 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 迭代器版本
vector<vector<int>> Solution_LeetCodeT100::t018_fourSum_iterator(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int>::iterator left = nums.begin();
    if (nums.size() < 4) return res;
    //左边界循环
    for (; left < nums.end() - 3; left++) {
        if (left != nums.begin() && *(left - 1) == *left)  continue;  // 去重复
        vector<int>::reverse_iterator right = nums.rbegin();
        for (int flag = 1; right.base() > left + 3 && flag; right++) {
            if (right != nums.rbegin() && *(right - 1) == *right) { continue; }  // 去重复
            // 优化一个判定， 当*right + *left - target > 2 * ( right + 1 ) right 左移
            //                当*right + *left + 2*(right+1) < target , left 左移 ，right循环提前结束
            if (*left + *right + long(*(right.base() - 2) * 2) < target) { flag = 0; continue; }
            if (*left + *right + long(*(left + 1)) * 2 > target) continue;
            vector<int>::iterator left_1 = left + 1;
            vector<int>::reverse_iterator right_1 = right + 1;
            while (left_1 < (right_1 + 1).base()) {
                if (left_1 != left + 1 && *(left_1 - 1) == *left_1) { left_1++; continue; }  // 去重复                if   // 去重复
                if (right_1 != right + 1 && *(right_1 - 1) == *right_1) { right_1++; continue; }  // 去重复                // 去重复
                if (long(*left + *left_1 + *right_1 + *right) == target) {
                    res.push_back({ *left,*left_1,*right_1,*right });
                    left_1++, right_1++;
                }
                else if (long(*left + *left_1 + *right_1 + *right) > target) right_1++;
                else left_1++;
            }
        }
    }
    return res;
}
// 下标版
vector<vector<int>> Solution_LeetCodeT100::t018_fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int left = 0; left < nums.size() - 3; left++) {
        if (left != 0) if (nums[left] == nums[left - 1]) continue;
        for (int right = nums.size() - 1; right >= left + 3; right--) {
            if (right != nums.size() - 1) if (nums[right] == nums[right + 1]) continue;
            // 优化判定  long 是为了防止越界
            if (nums[left] + nums[right] + long(nums[right-1] * 2) < target) { right = 0; continue; }
            if (nums[left] + nums[right] + long(nums[left + 1] * 2) > target) continue;

            int left_1 = left + 1, right_1 = right - 1;
            while (left_1 < right_1) {
                if (right_1 != right - 1) if (nums[right_1] == nums[right_1 + 1]) continue;
                if (left_1 != left + 1) if (nums[left_1] == nums[left_1 - 1]) continue;

                if (long(nums[left] + nums[left_1] + nums[right_1] + nums[right]) == target) {
                    res.push_back({ nums[left] , nums[left_1] , nums[right_1] , nums[right] });
                    left_1++, right_1--;
                }
                else if (long(nums[left] + nums[left_1] + nums[right_1] + nums[right]) > target)  right_1--;
                else left_1++;


            }
        }
    }
    return res;
}


/* 20. 有效的括号
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
bool Solution_LeetCodeT100::t020_isValid(string s)
{
    cout << s.size();
    if(s.size() %2 ==1) return false;
    stack<char> list;
    int i = 0;
    while (i < s.size()) {
        if (list.empty()) list.push(s[i]);
        else {
            if (abs(s[i] - list.top()) <= 2  && s[i] -  list.top() > 0 ) list.pop();
            else list.push(s[i]);
        }
        i++;
    }
    if (list.empty()) return true;
    else return false;
}
