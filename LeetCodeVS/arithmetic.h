#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include"LeetCodeT100.h"
using namespace std;



class Solution_arithmetic
{
public:

	int t_704_Binary_algorithm_search(vector<int>& nums, int target);

	vector<vector<int>> t_015_threeSum(vector<int>& nums);

	vector<string> t_017_letterCombinations(string digits);
	//19. 删除链表的倒数第 N 个结点
	ListNode* t_019_removeNthFromEnd_Recursion(ListNode* head, int n);
	ListNode* t_019_removeNthFromEnd_TwoPoingt(ListNode* head, int n);
	//21. 合并两个有序链表
	ListNode* t_021_mergeTwoLists(ListNode* list1, ListNode* list2);


private:

};
