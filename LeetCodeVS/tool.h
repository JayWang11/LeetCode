#pragma once

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<array>
#include<string>
#include<unordered_map>
#include<numeric>
#include<deque>
#include<queue>
#include<set>
#include<math.h>
#include<algorithm>
#include<stack>
#include<set>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
// ×ÖµäÊ÷
struct Trie {
	unordered_map<char, Trie*> children;
};
// ¶þ²æÊ÷
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};