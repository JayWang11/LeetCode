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

	//1247. �����ַ�ʹ���ַ�����ͬ
	int t1247_minimumSwap(string s1, string s2);
	//1255. �÷���ߵĵ��ʼ���
	int t1224_maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);
	int t1224_maxScoreWords_dfs(vector<string>& words, vector<char>& letters, vector<int>& score);

	//2363. �ϲ����Ƶ���Ʒ
	vector<vector<int>> t2363_mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2);
	vector<vector<int>> t2363_mergeSimilarItems_Hashmap(vector<vector<int>>& items1, vector<vector<int>>& items2);

	//������ 05.02. ��������ת�ַ���
	string m0502_printBin(double num);

	//1487. ��֤�ļ���Ψһ
	vector<string> t1487_getFolderNames(vector<string>& names);

	//982. ��λ��Ϊ�����Ԫ��
	int t0982_countTriplets(vector<int>& nums);

	//1599. ��ӪĦ���ֵ��������
	int t1599_minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost);

	//1590. ʹ������ܱ� P ����
	int t1590_minSubarray(vector<int>& nums, int p);

	//������ 17.05.  ��ĸ������
	vector<string> m1705_findLongestSubarray(vector<string>& array);


	//1617. ͳ�������г���֮�������� hard!
	vector<int> t1617_countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges);
	vector<int> t1617_countSubgraphsForEachDiameter_loss(int n, vector<vector<int>>& edges);

	//1605. �����к��еĺ�����о���
	vector<vector<int>> t1605_restoreMatrix(vector<int>& rowSum, vector<int>& colSum);

	//1615. ���������
	int t1615_maximalNetworkRank(int n, vector<vector<int>>& roads);

	//2488. ͳ����λ��Ϊ K ��������
	int t2488_countSubarrays(vector<int>& nums, int k);

	//1626. ��ì�ܵ�������
	int t1626_bestTeamScore(vector<int>& scores, vector<int>& ages);

	//1054. ������ȵ�������
	vector<int> t1054_rearrangeBarcodes(vector<int>& barcodes);

	//1335. �����ƻ�������Ѷ�
	int t1335_minDifficulty(vector<int>& jobDifficulty, int d);

	//LCP 41. �ڰ׷�ת��
	int LCP_41_flipChess(vector<string>& chessboard);

	//1186. ɾ��һ�εõ�����������
	int t1186_maximumSum(vector<int>& arr); 

	//1681. ��С��������
	int t1681_minimumIncompatibility(vector<int>& nums, int k);


	//445. ������� II
	ListNode* t0445_addTwoNumbers(ListNode* l1, ListNode* l2);

	//2178. ��ֳ������Ŀ����ż��֮��
	vector<long long> t2178_maximumEvenSplit(long long finalSum);

	//648. �����滻
	string t0648_replaceWords(vector<string>& dictionary, string sentence);

	//931. �½�·����С��
	int t0931_minFallingPathSum(vector<vector<int>>& matrix);

	//979. �ڶ������з���Ӳ��
	int t0979_distributeCoins(TreeNode* root);

	//834. ���о���֮��
	vector<int> t0834_sumOfDistancesInTree(int n, vector<vector<int>>& edges);

	//1851. ����ÿ����ѯ����С����
	vector<int> t1851_minInterval(vector<vector<int>>& intervals, vector<int>& queries);

	//874. ģ�����߻�����
	int t0874_robotSim(vector<int>& commands, vector<vector<int>>& obstacles);

	//918. ���������������
	int t0918_maxSubarraySumCircular(vector<int>& nums);

	//1499. ���㲻��ʽ�����ֵ
	int t1499_findMaxValueOfEquation(vector<vector<int>>& points, int k);

	//2208. ������ͼ�������ٲ�������
	int t2208_halveArray(vector<int>& nums);
	
	//2569. �������������Ͳ�ѯ
	vector<long long> t2569_handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries);

	//2050. ���пγ� III
	int t2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);

	//142. �������� II
	ListNode* t0142_detectCycle(ListNode* head);

	//143. ��������
	void t0143_reorderList(ListNode* head);

	//2681. Ӣ�۵�����
	int t2681_sumOfPower(vector<int>& nums);

	//822. ��ת��Ƭ��Ϸ
	int t0822_flipgame(vector<int>& fronts, vector<int>& backs);

	//722. ɾ��ע��
	vector<string> t0722_removeComments(vector<string>& source);

	//980. ��ͬ·�� III
	int t0980_uniquePathsIII(vector<vector<int>>& grid);

	//1289. �½�·����С�� II
	int t1289_minFallingPathSum(vector<vector<int>>& grid);


private:

	// ���� ���� 
	
	//648 ,String �зֺ���
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

	//648 �����ֵ����в��ҵ��ʵ����ǰ׺��
	string findRoot(string& str, Trie* root) {
		Trie* cur = root;
		string ret;
		for (auto c : str) {
			// ǰ�᣺ �ֵ�����Ϊ�� �� ̽�����ײ� ������
			if (cur->children.count('#'))
				return ret;
			// ֻ�и��ڵ���û�� ������Ż�ֱ�ӷ���str;
			if (!cur->children.count(c))
				return str;
			ret.push_back(c);
			cur = cur->children[c];
		}
		return ret;
	};

	//979 ����������
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

	//834 ����·��Ѱ��
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

