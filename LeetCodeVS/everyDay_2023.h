#pragma once
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
#include"tool.h"
using namespace std;



class Solution_everyDay
{

public:

	//1247. 交换字符使得字符串相同
	int t1247_minimumSwap(string s1, string s2);
	//1255. 得分最高的单词集合
	int t1224_maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);
	int t1224_maxScoreWords_dfs(vector<string>& words, vector<char>& letters, vector<int>& score);

	//2363. 合并相似的物品
	vector<vector<int>> t2363_mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2);
	vector<vector<int>> t2363_mergeSimilarItems_Hashmap(vector<vector<int>>& items1, vector<vector<int>>& items2);

	//面试题 05.02. 二进制数转字符串
	string m0502_printBin(double num);

	//1487. 保证文件名唯一
	vector<string> t1487_getFolderNames(vector<string>& names);

	//982. 按位与为零的三元组
	int t0982_countTriplets(vector<int>& nums);

	//1599. 经营摩天轮的最大利润
	int t1599_minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost);

	//1590. 使数组和能被 P 整除
	int t1590_minSubarray(vector<int>& nums, int p);

	//面试题 17.05.  字母与数字
	vector<string> m1705_findLongestSubarray(vector<string>& array);


	//1617. 统计子树中城市之间最大距离 hard!
	vector<int> t1617_countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges);
	vector<int> t1617_countSubgraphsForEachDiameter_loss(int n, vector<vector<int>>& edges);

	//1605. 给定行和列的和求可行矩阵
	vector<vector<int>> t1605_restoreMatrix(vector<int>& rowSum, vector<int>& colSum);

	//1615. 最大网络秩
	int t1615_maximalNetworkRank(int n, vector<vector<int>>& roads);

	//2488. 统计中位数为 K 的子数组
	int t2488_countSubarrays(vector<int>& nums, int k);

	//1626. 无矛盾的最佳球队
	int t1626_bestTeamScore(vector<int>& scores, vector<int>& ages);

	//1054. 距离相等的条形码
	vector<int> t1054_rearrangeBarcodes(vector<int>& barcodes);

	//1335. 工作计划的最低难度
	int t1335_minDifficulty(vector<int>& jobDifficulty, int d);

	//LCP 41. 黑白翻转棋
	int LCP_41_flipChess(vector<string>& chessboard);

	//1186. 删除一次得到子数组最大和
	int t1186_maximumSum(vector<int>& arr); 

	//1681. 最小不兼容性
	int t1681_minimumIncompatibility(vector<int>& nums, int k);


	//445. 两数相加 II
	ListNode* t0445_addTwoNumbers(ListNode* l1, ListNode* l2);

	//2178. 拆分成最多数目的正偶数之和
	vector<long long> t2178_maximumEvenSplit(long long finalSum);

	//648. 单词替换
	string t0648_replaceWords(vector<string>& dictionary, string sentence);

	//931. 下降路径最小和
	int t0931_minFallingPathSum(vector<vector<int>>& matrix);

	//979. 在二叉树中分配硬币
	int t0979_distributeCoins(TreeNode* root);

	//834. 树中距离之和
	vector<int> t0834_sumOfDistancesInTree(int n, vector<vector<int>>& edges);

	//1851. 包含每个查询的最小区间
	vector<int> t1851_minInterval(vector<vector<int>>& intervals, vector<int>& queries);

	//874. 模拟行走机器人
	int t0874_robotSim(vector<int>& commands, vector<vector<int>>& obstacles);

	//918. 环形子数组的最大和
	int t0918_maxSubarraySumCircular(vector<int>& nums);

	//1499. 满足不等式的最大值
	int t1499_findMaxValueOfEquation(vector<vector<int>>& points, int k);

	//2208. 将数组和减半的最少操作次数
	int t2208_halveArray(vector<int>& nums);
	
	//2569. 更新数组后处理求和查询
	vector<long long> t2569_handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries);

	//2050. 并行课程 III
	int t2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);

	//142. 环形链表 II
	ListNode* t0142_detectCycle(ListNode* head);

	//143. 重排链表
	void t0143_reorderList(ListNode* head);

	//2681. 英雄的力量
	int t2681_sumOfPower(vector<int>& nums);

	//822. 翻转卡片游戏
	int t0822_flipgame(vector<int>& fronts, vector<int>& backs);

	//722. 删除注释
	vector<string> t0722_removeComments(vector<string>& source);

	//980. 不同路径 III
	int t0980_uniquePathsIII(vector<vector<int>>& grid);

	//1289. 下降路径最小和 II
	int t1289_minFallingPathSum(vector<vector<int>>& grid);


private:

	// 工具 函数 
	
	//648 ,String 切分函数
	vector<string> split(string& str, char ch) {
		int pos = 0;
		int start = 0;
		vector<string> ret;
		while (pos < str.size()) {
			while (pos < str.size() && str[pos] == ch)
				pos++;
			start = pos;
			while (pos < str.size() && str[pos] != ch)
				pos++;
			if (start < str.size())
				ret.push_back(str.substr(start, pos - start));
		}
		return ret;
	};

	//648 ，在字典树中查找单词的最短前缀。
	string findRoot(string& str, Trie* root) {
		Trie* cur = root;
		string ret;
		for (auto c : str) {
			// 前提： 字典树不为空 ， 探索到底层 ，返回
			if (cur->children.count('#'))
				return ret;
			// 只有根节点下没有 的情况才会直接返回str;
			if (!cur->children.count(c))
				return str;
			ret.push_back(c);
			cur = cur->children[c];
		}
		return ret;
	};

	//979 二叉树遍历
	int t0979_dfs(TreeNode* root, int score) {

		if (root->left) {
			t0979_dfs(root->left, score);
			root->val += root->left->val;
			score += abs(1 - root->left->val);
		}
		if (root->right) {
			t0979_dfs(root->right, score);
			root->val += root->right->val;
			score += abs(1 - root->right->val);
		}
		return root->val - 3;
	}

	//834 树的路径寻找
	int t0834_dist(int  start, int end, int &n ,  vector<vector<int>> dist) {
		for (int i = 0; i < n; i++) {
			if (i == end) continue;
			if (dist[start][i] > 0) {
				if (dist[i][end] < 0) {
					dist[i][end] = t0834_dist(i, end, n, dist);
				}
				if (dist[start][end] > 0)
					dist[start][end] = min(dist[start][end], dist[i][end] + dist[start][i]);
				else
					dist[start][end] = dist[i][end] + dist[start][i];

			}
		}
	}
};


