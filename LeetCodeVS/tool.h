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
// 字典树
struct Trie {
	unordered_map<char, Trie*> children;
};
// 二叉树
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};


//线段树
template < class T>
class SegMentTree
{
public:
	SegMentTree(vector<int>  nums) { SegTree = vector<SegmentTree>(nums.size() * 4 + 1); bulid( 1, 1, nums.size(), nums); };
	void bulid(int treeRoot, int l, int r, const vector<int>& nums);
	void change(int  tR, int l, int r);
	long long   find(int tR, int l, int r);

private:
	struct SegmentTree
	{
		int  l, r;
		bool  lazyTag;
		long long sum;
		SegmentTree() {
			this->l = 0;
			this->r = 0;
			this->sum = 0;
			this->lazyTag = false;

		}
	};
	vector< SegmentTree> SegTree;

	void pushdown(int tR);
};


///线段树的实现代码

/// 建树
template<class T>
inline void SegMentTree<T>::bulid(int treeRoot, int  l, int r, const vector<int>& nums)
{
	SegTree[treeRoot].l = l;
	SegTree[treeRoot].r = r;
	if (l == r) {
		SegTree[treeRoot].sum = nums[l - 1];

	}
	else {
		bulid(treeRoot << 1, l, (l + r) / 2, nums);
		bulid((treeRoot << 1) + 1, (l + r) / 2 + 1, r, nums);
		SegTree[treeRoot].sum = SegTree[treeRoot << 1].sum + SegTree[(treeRoot << 1) + 1].sum;

	}
	SegTree[treeRoot].lazyTag = false;
}


/// 修改
template<class T>
inline void SegMentTree<T>::change(int  tR, int l, int r)
{
	//  区间被包含 
	if (l <= SegTree[tR].l && r >= SegTree[tR].r) {
		// 反转数据
		SegTree[tR].sum = (SegTree[tR].r - SegTree[tR].l + 1) - SegTree[tR].sum;
		SegTree[tR].lazyTag = !SegTree[tR].lazyTag;
		return;
	}
	pushdown(tR);

	if (SegTree[tR << 1].r >= l)
		change(tR << 1, l, r);
	if (SegTree[(tR << 1) + 1].l <= r) {
		change((tR << 1) + 1, l, r);
	}
	SegTree[tR].sum = SegTree[tR * 2].sum + SegTree[tR * 2 + 1].sum;
}

///查找
template<class T>
inline long long  SegMentTree<T>::find(int tR, int l, int r)
{

	if (l <= SegTree[tR].l && r >= SegTree[tR].r) {
		return SegTree[tR].sum;
	}
	pushdown(tR);
	long long  res = 0;
	if (SegTree[tR << 1].r >= l) {
		res += find(tR << 1, l, r);
	}
	if (SegTree[(tR << 1) + 1].l <= r) {
		res += find((tR << 1) + 1, l, r);

	}
	return res;

}

/// 向下传递lazyTag
template<class T>
inline void SegMentTree<T>::pushdown(int tR)
{
	if (SegTree[tR].lazyTag) {
		SegTree[tR << 1].sum = SegTree[tR << 1].r - SegTree[tR << 1].l + 1 - SegTree[tR << 1].sum;
		SegTree[tR << 1].lazyTag = !SegTree[tR << 1].lazyTag;
		SegTree[(tR << 1) + 1].sum = SegTree[(tR << 1) + 1].r - SegTree[(tR << 1) + 1].l + 1 - SegTree[(tR << 1) + 1].sum;
		SegTree[(tR << 1) + 1].lazyTag = !SegTree[(tR << 1) + 1].lazyTag;
		SegTree[tR].lazyTag = false;

	}
}