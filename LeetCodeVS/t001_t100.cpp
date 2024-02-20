#include"LeetCodeT100.h"
#include <functional>
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



bool Solution_LeetCodeT100::t010_isMatch(string s, string p)
{

    // 动态规划 ，用 dp[i][j] 表示 p前j个元素是否能和s的前i个元素进行匹配·
    vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));
    for (auto& dp1 : dp)
        dp1[0] = 1;
    int i , j = 1, index = 0, flag = 0;
    char  t;
    while (j - 1 < p.size()) {
        t = p[j - 1];
        if (j < p.size() && p[j] == '*') {
            dp[j][index] = dp[j - 1][index];
            dp[j+1][index] = dp[j][index];
            for ( i = index+1; i <= s.size(); i++ ) {
                dp[j][i] = int (dp[j-1][i] || 
                    min( int(dp[j - 1][i - 1] || dp[j][i-1]), int(s[i - 1] == t || t == '.')));
                dp[j + 1][i] = dp[j][i];
            }
            j += 2;
        }
        else {
            index++;
            for ( i = index; i <= s.size(); i++) {
                dp[j][i] = min(dp[j - 1][i - 1], int(s[i - 1] == t || t == '.'));
                if (dp[j][i]) {
                    index = min(index, i);
                }
            }
            j++;
        }
        if (index > s.size()) return false;
    }
    for (auto &d : dp) {
        for (auto& p : d)
            cout << p << " ";
        cout << endl;
    }
    cout << dp[p.size()][s.size()];
    if (index > s.size()) return false;
    return dp[p.size()][s.size()];
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

/*22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

*/
vector<string> Solution_LeetCodeT100::t022_generateParenthesis(int n)
{

    //dfs 深度遍历 + 剪枝
    if (n == 1) return{ "()" };
    vector<string> res;
    string s = "(";
    int b = 1, l = 1, r = 0;
    t022_dfs(s , b, n, l ,r,  res);
    return res;
}

/*28. 找出字符串中第一个匹配项的下标
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
*/
int Solution_LeetCodeT100::t028_strStr(string haystack, string needle)
{
    // kmp算法
    if (needle.size() > haystack.size()) return -1;
    vector<int> next(needle.size(), 0);
    int pos = 0;
    // 构造next
    for (int i = 1; i < needle.size(); i++) {
        while (needle[i] != needle[pos] && pos) {
            pos = next[pos - 1];
        }
        if (needle[i] == needle[pos]) pos++;
        next[i] = pos;
    }
    pos = 0;
    //匹配 
    for (int i = 0; i < haystack.size(); i++) {
        while (haystack[i] != needle[pos] && pos) pos = next[pos - 1];
        if (haystack[i] == needle[pos]) pos++;
        if (pos == needle.size())
            return i - pos + 1;
    }
    return -1;
}


/*29. 两数相除
给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。

 */
int Solution_LeetCodeT100::t029_divide(int dividend, int divisor)
{
    if (dividend == INT_MIN) {
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return INT_MAX;
    }
    if (dividend == divisor) return 1;
    long long dd = dividend, ds = divisor;
    int flag = 1, res = 0, n = 31;
    if (dividend < 0) {
        flag *= -1;
        dd *= -1;
    }
    if (divisor < 0) {
        flag *= -1;
        ds = -ds;
    }
    while (dd >= ds) {
        while (dd >> n < ds) {
            n--;
        }
        res += 1 << n;
        dd -= ds << n;
    }
    return res * flag;
 
}

/*30. 串联所有单词的子串
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联字串在 s 中的开始索引。你可以以 任意顺序 返回答案。
*/
vector<int> Solution_LeetCodeT100::t030_findSubstring(string s, vector<string>& words)
{
    // 滑动窗口
    unordered_map < string, int> words_m;
    unordered_map < string, int> words_t;

    vector<int> res;
    int word_len = words[0].size() , word_n = words.size();
    for (auto& w : words)
        words_m[w]++;
    // 三种开始区间
    for (int i = 0; i < word_len; i++) {
        int flag = 0 , start = i;
        for (int j = i; j < s.size(); j += word_len) {
            if (words_m[s.substr(j, word_len)]) {
                words_t[s.substr(j, word_len)] ++;
                flag++;

                while (words_t[s.substr(j, word_len)] > words_m[s.substr(j, word_len)]) {
                    words_t[s.substr(start, word_len)] --;
                    start += word_len;
                    flag--;
                }
                if (flag == word_n) {
                    res.push_back(start);
                    words_t[s.substr(start, word_len)] --;
                    start += word_len;
                    flag--;
                }
            }
            else {
                words_t.clear();
                start = j + word_len;
                flag = 0;

            }
        }
        words_t.clear();

    }
    return res;
}


/*31. 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。
*/
void Solution_LeetCodeT100::t031_nextPermutation(vector<int>& nums) {

    // 字典序 ： 在这题直观理解就是按照数值排序
    if (nums.size() == 1);
    else {
        int flag = 1, len = nums.size() , pos = -1;
        for (int i = len - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                pos = i-1;
                i = 0;
            }
        }
        if (pos == -1) {
            // 全倒序
            reverse(nums.begin(), nums.end());
        }
        else {
            for (int i = len - 1; i > pos; i--) {
                if (nums[i] > nums[pos]) {
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
            sort(nums.begin() + pos+1, nums.end());
        }
    }
    for (auto& n : nums)
        cout << n << endl;
}

/**/
int Solution_LeetCodeT100::t032_longestValidParentheses(string s)
{
   // 栈
    int res =0 ;
    stack< int> stk;
    // 最下面放一个'('
    stk.push(-1);
    for (int i = 0; i < s.size(); i++) {
        // 遇到'(’ 入栈
        if (s[i] == '(')
            stk.push(i);
        // ’）' 出栈，并用当前指针减去栈顶指针，就是该子括号串的最大连续值
        else {
            stk.pop();
            if (stk.empty())
                stk.push(i);
            else {
                res = max(res, i - stk.top());
            }
        }
    }
    return res;

}

/*33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/
int Solution_LeetCodeT100::t033_search(vector<int>& nums, int target)
{
    if (target > *nums.rbegin() && target < *nums.begin()) return -1;
    if (target == *nums.rbegin() || target == *nums.begin()) return target == *nums.begin() ? 0 : nums.size() - 1;
    if (nums.size() == 1) return target == nums[0] ? nums[0] : -1;
    int mid = (nums.size()-1) / 2, left = 0, right = nums.size() - 1;
    if (target > *nums.begin()) {
        while (nums[mid] != target && right > left) {
            if (nums[mid] > target || nums[mid] < nums[left])
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
         
            mid = (left + right) / 2;
        }
    }
    else {
        while (nums[mid] != target && right > left) {
            if (nums[mid] > nums[right] || nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    if (right <= left) return nums[left] == target ? left : -1;
    else return mid;
}

/*34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
*/
vector<int> Solution_LeetCodeT100::t034_searchRange(vector<int>& nums, int target)
{
    // 二分查找
    int len = nums.size();
    if (!len) return { -1,-1 };
    vector<int> res(2);
    auto find = [&](int l, int r, bool up) ->int {
        while (l < r) {
            // cout << "l :" << l << "  r :" << r << endl;
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else if (up && nums[max(0, mid - 1)] < target)
                return mid;
            else if (!up && nums[min(len - 1, mid + 1)] > target)
                return mid;
            else {
                if (up) r = mid - 1;
                else  l = mid + 1;
            }
        }
        if (nums[l] == target) return l;
        else return len;

    };
    res[0] = find(0, len - 1, true);
    res[1] = find(0, len - 1, false);
    if (res[0] < len && res[1] < len && nums[res[0]] == nums[res[1]] && nums[res[0]] == target)  return res;
    return { -1,-1 };
}

/*
* 35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/
int Solution_LeetCodeT100::t035_searchInsert(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        }
        else if (nums[mid] < target)
            l = mid + 1;
        else return mid;
    }
    if (target > nums[l]) return l + 1;
    // 加max是为了处理越界情况
    else return max(0, l);
}

/*36. 有效的数独
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
*/
bool Solution_LeetCodeT100::t036_isValidSudoku(vector<vector<char>>& board)
{
    vector< vector<bool>> flag(27, vector<bool>(9, false));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int n = (board[i][j] - '0') -1 ;
                if (flag[i][n]) return false;
                else flag[i][n] = true;
                cout << " hang ";
                if (flag[9 + j][n]) return false;
                else flag[9 + j][n] = true;
                cout << " lie ";

                if (flag[18 + i / 3 + (j / 3) * 3][n]) return false;
                else  flag[18 + i / 3 + (j / 3) * 3][n] = true;
                cout << " block" << endl;

            }
        }
    }
    return true;
}

/*37. 解数独
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/
void Solution_LeetCodeT100::t037_solveSudoku(vector<vector<char>>& board)
{   
    vector<vector<bool>> flag;
    auto isOk = [&](int i, int j, int num)-> bool {
        if (flag[i][num]) return false;
        if (flag[9 + j][num]) return false;
        if (flag[18 + (i / 3) + j * 3][num]) return  false;
        return true;

    };

}

string Solution_LeetCodeT100::t038_countAndSay(int n)
{
    if (n == 1) return "1";
        string res = "1";
        while (n-1) {
            char p = '0';
            int  c_n = 0;
            string res1;
            for (auto c : res) {
                if (c == p) {
                    c_n++;
                }
                else {
                    if (c_n)
                        res1 += to_string(c_n) + p;
                    p = c;
                    c_n = 1;
                }
            }
            res = res1 + to_string(c_n) + p;
            n--;
        }
    return res;
}

/*39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
*/
vector<vector<int>> Solution_LeetCodeT100::t039_combinationSum(vector<int>& cds, int target)
{
    vector<vector<int>> res;
    sort(cds.begin(), cds.end());
    function< void(int,int, int,vector<int> )> dps = [&](int n,int l ,int low, vector<int> r )->void {
        if (l)
            r.push_back(l);
        if (n == 0) {
            res.push_back(r);
        }
        else {
            if (find(cds.begin(), cds.end(), n) != cds.end()) {
                dps(0, n, low, r);
            }
            for (int i = low; i < cds.size() && cds[i] <= n / 2; i++) {
                int d = n - cds[i];
                // low 负责剪枝
                dps(d, cds[i], i, r);
                
            }
        }
    };
    dps(target,0,0, {});
    return res;
    //return{};
}

/*40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
*/
vector<vector<int>> Solution_LeetCodeT100::t040_combinationSum2(vector<int>& cds, int target)
{
    vector<vector<int>> res;
    sort(cds.begin(), cds.end());
    vector<bool> b ( cds.size() , false);
    function<void(int ,int ,vector<int>)>dfs = [&](int n,  int low, vector<int> r ) -> void {
       
        if (low>=0) {
            r.push_back(cds[low]);
        }
        if (n == 0)
            res.push_back(r);
        else if (n > 0)
        {
            for (int i = low+1; i < cds.size() && cds[i] <=  n; i++) {
                if (i > low+1 && cds[i] == cds[i - 1])
                    continue;
                dfs(n - cds[i],i, r );
            }
        }
    };
    dfs(target,-1 ,{});
    return  res;
}


/*41. 缺失的第一个正数
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/
int Solution_LeetCodeT100::t041_firstMissingPositive(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0 && nums[i] <= nums.size()) {

            int t = nums[nums[i] - 1];
            if (t == nums[i])
                continue;
            nums[nums[i] - 1] = nums[i];
            nums[i] = t;
            if (t > 0 && t <= nums.size())
                i--;
        }
        else
            nums[i] = 0;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i != nums[i] - 1)
            return i + 1;
    }
    return nums.size() + 1;
}

/*42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
int Solution_LeetCodeT100::t042_trap(vector<int>& height)
{
    int len = height.size();
    int res = 0, l = 0, r = 0, t1 = 0 , t2 = 0;
    for (int i = 0; i <len ; i++) {
        if (height[i] >= l) {
            l = height[i];
            res += t1; 
            t1 = 0;
        }
        else {
            t1 += l - height[i];
        }
        if (height[len - 1 - i] > r) {
            r = height[len - 1 - i];
            res += t2;
            t2 = 0;
        }
        else {
            t2 += r - height[len - 1 - i];
        }
    }
    return res;
}

/*43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
*/
string Solution_LeetCodeT100::t043_multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    // 探究乘法运算本质，分解为num1和num2每一位数字的乘法运算
    string res(num1.size() + num2.size(), '0');
    cout << res << endl;
    for (int i = num1.size()-1; i >= 0 ; i--) {
        for (int j = num2.size()-1; j >=0; j--) {
            int t = (num1[i] - '0') * (num2[j] - '0');
            int r = res[i + j + 1 ] -'0' + t % 10;
            res[i + j + 1 ] = r % 10 + '0';
            r = res[i + j ] -'0' + t / 10 + r / 10;
            res[i + j ] = r % 10 + '0';
            int k = i + j ;
            while (r / 10 && k >=0) {
                k--;
                r = res[k] - '0' + r / 10;
                res[k] = r % 10 + '0';
            }
        }
    }

    return  res[0] == '0' ? string(res.begin() + 1, res.end()) : res;
}

/*44. 通配符匹配
困难
1.1K
给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符序列（包括空字符序列）。
判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
*/
bool Solution_LeetCodeT100::t044_isMatch(string s, string p)
{
    // 直接参考 t_010 ,正则表达式匹配,动态规划完事
    // 可以想想怎么优化内存开销，dp能不能用单队列表示
    vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, false));
    dp[0][0] = true;
    int s_index = -1;
    for (int p_i = 0; p_i < p.size(); p_i++) {
        if (p[p_i] == '*') {
            int i = s_index;
            while (i < s.size() || i == -1) {
                dp[p_i + 1][i + 1] = true;
                i++;
            }
        }
        else {
            s_index++;
            if (s_index == s.size()) return false;
            int i = s_index;
            int flag = s.size();
            while (i < s.size()) {
                if ((s[i] == p[p_i] || p[p_i] == '?') && dp[p_i][i]) {
                    dp[p_i + 1][i + 1] = true;
                    flag = min(flag, i);
                }
                i++;
            }
            if (flag == s.size()) return false;
            s_index = flag;
        }
    }
    return dp[p.size()][s.size()];
}

/*45. 跳跃游戏 II
中等
2.2K
相关企业
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
*/
int Solution_LeetCodeT100::t045_jump(vector<int>& nums)
{
    // 动态规划 + 贪心算法？
    if (nums.size() == 1) {
        return 0;
    }
    int res = 1, len = nums.size();
    for (int i = 0; i < len; ) {
        int Max = i + nums[i], Max_i = i;
        if (Max >= len - 1) return res;
        for (int j = i + 1; j < len && j <= i + nums[i]; j++) {
            if (nums[j] + j > Max) {
                Max = nums[j] + j;
                Max_i = j;
            }
        }
        res++;
        i = Max_i;
    }
    return 0;
}

/*46. 全排列
中等
2.6K
相关企业
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/
vector<vector<int>> Solution_LeetCodeT100::t046_permute(vector<int>& nums)
{
    vector<vector<int>> res; 
    function<  void(int)> dfs = [&]( int len )-> void {
        if (len  == nums.size()) res.push_back(nums);
        else {
            for (int i = len ; i < nums.size(); i++) {
                swap(nums[len], nums[i]);
                dfs(len + 1);
                swap(nums[len], nums[i]);

            }
        }
    };
    dfs(0);
    return  res ;
}

/*47. 全排列 II
中等
1.4K
相关企业
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/
vector<vector<int>> Solution_LeetCodeT100::t047_permuteUnique(vector<int>& nums)
{
    if (nums.size() == 1) return { nums };
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    function<  void(int)> dfs = [&](int len)-> void {
        if (len == nums.size()) res.push_back(nums);
        else {
            for (int i = len; i < nums.size(); i++) {
                if ((nums[i] == nums[len] && i != len) ) continue;
                if ( i> len && nums[i - 1] -nums[i] == 0) continue;
                swap(nums[len], nums[i]);
                dfs(len + 1);
                swap(nums[len], nums[i]);
            }
        }
    };
    dfs(0);
    return  res;
}










//22 深度遍历辅助函数
bool Solution_LeetCodeT100::t022_dfs(const string& s, const int& b, int& n, const int& l, const int& r, vector<string>& res)
{
    if (b < 0) return 0;
    else if (s.size() == n * 2)
        res.push_back(s);
    else {
        if (l < n) {
            t022_dfs(s + '(', b + 1, n, l + 1, r, res);
        }
        if (r < n) {
            t022_dfs(s + ')', b - 1, n, l, r + 1, res);
        }
    }
    return false;
}

//30 深度遍历辅助函数
void Solution_LeetCodeT100::dfs_str(string& s, string s_w, int& s_len, vector<string>& words, vector<int>& res, vector<bool>& index)
{
    for (int i = 0; i < words.size(); i++) {
        if (index[i]) {
            string s_w_t = s_w;
            vector<bool> index_t = index;
            int pos = 0;
            s_w_t += words[i];
            index_t[i] = false;
            auto k = s.find(s_w_t, pos);
            while (k != string::npos) {
                if (find(res.begin(), res.end(), k) != res.end()) {
                }
                else if (s_w_t.size() == s_len  ) {
                    res.push_back(k);
                }
                else
                    dfs_str(s, s_w_t, s_len, words, res, index_t);
  /*              cout << "s_w_t ：" << s_w_t;
                cout << "  s_w_t.size() ：" << s_w_t.size();
                cout << "  s_len ：" << s_len << endl;*/
                pos = k+1;
                k = s.find(s_w_t, pos);
            }
        }
    }
}


