#include "arithmetic.h"

/**
* 二分查找
* 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/
int Solution_arithmetic::t_704_Binary_algorithm_search(vector<int>& nums, int target)
{

    int upper = nums.size() - 1, lower = 0;
    int index;
    while (upper >= lower) {
        index = (upper - lower) / 2 + lower;
        if (nums[index] == target) return index;
        else if (nums[index] < target)  lower = index + 1;
        else   upper = index - 1;

    }
    return -1;
}

/*15. 三数之和  双指针问题
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> Solution_arithmetic::t_015_threeSum(vector<int>& nums)
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


static vector<string> word = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };



/** 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 递归函数 ，做枚举使用
void  getChar(vector<string>& res, string digits, string s, int i) {
    if (i < digits.size()) {
        for (char c : word[digits[i] - '2']) {
            //cout << "test" << endl;

            if (i < digits.size() - 1) getChar(res, digits, s+c, i + 1) ;
            else  res.push_back(s+c);
        }
    }
}

vector<string> Solution_arithmetic::t_017_letterCombinations(string digits)
{
    vector<string> res;
    string s;
    if (digits.size() == 0) return res;
    getChar(res, digits, s, 0);
    return res;
}



/* 19. 删除链表的倒数第 N 个结点
* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/
// 递归函数
ListNode* findN(ListNode* node, int& n) {
    if (node->next != nullptr) {
        node->next = findN(node->next, n);
    }
    n -= 1;
    if (n == 0) {
        return node->next;
    }
    else
        return node;
   
}
// 递归法，本质上是利用栈的特性
ListNode* Solution_arithmetic::t_019_removeNthFromEnd_Recursion(ListNode* head, int n)
{
    return findN( head , n);
}
// 双指针。 简直太帅了,但是实测内存开销依然大。
ListNode* Solution_arithmetic::t_019_removeNthFromEnd_TwoPoingt(ListNode* head, int n)
{
    ListNode* tmp = new ListNode(0, head);
    ListNode* first = tmp;
    ListNode* second = tmp;
    for (int i = 0; i < n; i++) first = first->next;
    while (first->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    if(second->next!= nullptr) second->next = second->next->next;
    head = tmp->next;
    delete tmp;
    return head;
}



/*21. 合并两个有序链表
* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/
ListNode* Solution_arithmetic::t_021_mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* head = new ListNode();
    ListNode* tmp = head;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            tmp->next = list1;
            list1 = list1->next;
        }
        else {
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    if (list1 == nullptr) tmp->next = list2;
    else tmp->next = list1;
    tmp = head->next;
    delete head;
    return tmp;
}

