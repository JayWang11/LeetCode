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
private:

};


