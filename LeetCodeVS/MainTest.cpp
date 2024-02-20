#include <iostream>
#include "LeetCodeT100.h"
#include"arithmetic.h"
#include"everyDay_2023.h"
#include"everyDay_2024.h"




using namespace std;

// kadane算法
int MaxSonList(vector<int>& num) {
	int dp = num[0], res = 0;
	for (int i = 1; i < num.size(); i++) {
		dp = max(dp, 0) + num[i];
		res = max(dp, res);
	}
	return res;
}

// 背包dp
int backpack_dp(int &n , int &W  , vector<int> &v , vector<int> &w ) {
	vector <int> f( v.size() );
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];  // 读入数据
	// 自底向上 , 从f[0][0] 开始更新
	for (int i = 1; i <= n; i++)
		for (int l = W; l >= w[i]; l--)
			if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];  // 状态方程
	cout << f[W];
	return 0;
}

// 机器人碰撞问题
vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
	unordered_map < int, int  > m;
	map<int, pair<int, int>> t;
	stack<int> s;
	vector<int> res;
	for (int i = 0; i < positions.size(); i++) {
		m[positions[i]] = i;
	}
	int l = 0  ,r = 1,flag =1 , p =0 ;
	sort(positions.begin(), positions.end());
	while( p != positions.size()) {
		int r = m[positions[p]];
		if (!s.size()) { s.push(r), p++; res.push_back(healths[r]); }
		else {
			int l = s.top();	
			if (directions[l] == directions[r] || (directions[l] == 'L' && directions[r] == 'R')) {
				s.push(r);
				p++;
			}
			else if (healths[l] > healths[r]) {
				healths[l]--;
				healths[r] = 0;
				res[res.size()-1]--;				
				p++;
			}
			else if (healths[l] == healths[r]) {
				s.pop();
				healths[l] = 0;
				healths[r] = 0;

				p++;
			}
			else {
				healths[l] = 0;
				healths[r]--;
				s.pop();

			}
		}
	
	}

	for (auto i : healths) {
		if (i)
			res.push_back(i);
	}
	return res;
}


vector<string> splitWordsBySeparator(vector<string> words, char separator) {
	int len = words.size();
	for (int i = 0; i < len; i++) {
		string s = "";
		cout << "s :" << s << endl;
		cout << " words[i] :" << words[i] << endl;
		for (int j = 0; j < words[i].size(); j ++ ) {
			if (words[i][j] != separator)
				s += words[i][j];
			else {
				if (s.size()) {
					words.push_back(s);
					s = "";
				}
			}
			cout << "s :" << s << endl;

		}
		if (s.size())
			words.push_back(s);
	}
	words.erase(words.begin(), words.begin() + len);
	return words;

}

int removeDuplicates(vector<int>& nums) {

	int i = 0, it = 0;
	while (i < nums.size()) {
		int k = 1;
		nums[it] = nums[i];
		while ((i + k < nums.size()) && (nums[i] != nums[i + k])) { k++; }
		nums[it + 1] = nums[i + k];
		i = i + k;
		it++;
	}

	return it;
}

int main() {
    vector<int> test_1 = { 3,9,20,15,7 };
	vector<int> test_2 = { 9,3,15,20,7 };
	vector<int> test_3 = { 36,41,21,10,49,49,17,44,48,18 };
	string s = "RRLLRLLLLL";
	
	vector<string> words = { "main() {", "   func(1);", "   /** / more comments here", "   float f = 2.0", "   f += f;", "   cout << f; */", "}" };
	vector<string> names = { "kaido","kaido(1)","kaido","kaido(1)","kaido(2)" };
	vector<vector<char>> board = { 
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'} };

	vector<vector<int>> list_2 = { {-2,-18,31,-10,-71,82,47,56,-14,42},{-95,3,65,-7,64,75,-51,97,-66,-28},{36,3,-62,38,15,51,-58,-90,-23,-63},{58,-26,-42,-66,21,99,-94,-95,-90,89},{83,-66,-42,-45,43,85,51,-86,65,-39},{56,9,9,95,-56,-77,-2,20,78,17},{78,-13,-55,55,-7,43,-98,-89,38,90},{32,44,-47,81,-1,-55,-5,16,-81,17},{-87,82,2,86,-88,-58,-91,-79,44,-9},{-96,-14,-52,-8,12,38,84,77,-51,52} };
	vector<string> list_3 = { "....X.","....X.","XOOO..","......","......" };

	vector<int> x = { 4,12,10,1,0 };
	vector<int> y = { 1,0,3,16,7 };
	Solution_LeetCodeT100 s_t100;
	Solution_arithmetic s_a;
	Solution_everyDay s_e;
	everyDay_2024 s_e_24;

	cout << " 2023 : " << endl;
	//s_e.t1054_rearrangeBarcodes(test_L);
	//s_e.LCP_41_flipChess(list_3);
	//cout <<s_e.t1186_maximumSum(test_1);
	//cout << MaxSonList(test_1);
	//cout << s_e.t1681_minimumIncompatibility(test_1, 4);
	//s_e.t0648_replaceWords({words } ,"the cattle was rattled by the battery" );
	//s_e.t0931_minFallingPathSum(list_2);
	//s_e.t0834_sumOfDistancesInTree(6, list_2);
	//s_e.t2208_halveArray(test_1);
	//s_e.t2569_handleQuery(test_1, test_2,  list_2);
	//s_e.t2050_minimumTime(2, list_2, test_1);
	//s_e.t2681_sumOfPower(test_1);
	//s_e.t0822_flipgame(test_1 , test_2);
	//s_e.t0722_removeComments(words);
	//cout << s_e.t1289_minFallingPathSum(list_2);
	//cout << s_e.t0980_uniquePathsIII(list_2);
	//survivedRobotsHealths(test_2 ,test_3 , s);



	// t100 刷题

	//s_t100.t010_isMatch( "a" , ".*..a*");
	//cout<<s_t100.t028_strStr("aabaaabaaac" , "aabaaac");
	//cout << s_t100.t029_divide(INT_MIN , 3);
	//s_t100.t030_findSubstring("aaaaaaaaaaaaaa", words);
	//s_t100.t031_nextPermutation(test_1);
	//s_t100.t032_longestValidParentheses(")()())");
	//auto t = s_t100.t034_searchRange(test_1, 8);
	//s_t100.t036_isValidSudoku(board);
	//s_t100.t038_countAndSay(9);
	//s_t100.t039_combinationSum(test_1, 10);
	//s_t100.t040_combinationSum2(test_1, 8);
	//cout << s_t100.t043_multiply( "123", "456");
	//s_t100.t044_isMatch("mississippi", "m??*ss*?i*pi");
	//s_t100.t045_jump(test_1);
	//s_t100.t047_permuteUnique(test_1);




	cout << " 2024 ： " << endl;
	s_e_24.t0105_buildTree(test_1, test_2);

	cout << endl;

}
