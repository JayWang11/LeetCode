#include <iostream>
#include "LeetCodeT100.h"
#include"arithmetic.h"
#include"everyDay.h"



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
    vector<int> test_1 = { 6,3,8,1,3,1,2,2 };
	vector<int> test_2 = { 20,47,39,28,3,7,12,1,37,33 };
	vector<int> test_3 = { 36,41,21,10,49,49,17,44,48,18 };
	string s = "RRLLRLLLLL";
	
	vector<string> words = { "cat","bat","rat" };
	vector<string> names = { "kaido","kaido(1)","kaido","kaido(1)","kaido(2)" };

	vector<vector<int>> list_2 = { {2,1,3},{6,5,4},{7,8,9} };
	vector<string> list_3 = { "....X.","....X.","XOOO..","......","......" };

	vector<int> x = { 4,12,10,1,0 };
	vector<int> y = { 1,0,3,16,7 };
	Solution_LeetCodeT100 s_t100;
	Solution_arithmetic s_a;
	Solution_everyDay s_e;


	//s_e.t1054_rearrangeBarcodes(test_L);
	//s_e.LCP_41_flipChess(list_3);
	//cout <<s_e.t1186_maximumSum(test_1);
	//cout << MaxSonList(test_1);
	//cout << s_e.t1681_minimumIncompatibility(test_1, 4);
	//s_e.t0648_replaceWords({words } ,"the cattle was rattled by the battery" );
	s_e.t0931_minFallingPathSum(list_2);

	//survivedRobotsHealths(test_2 ,test_3 , s);



	// t100 刷题

	//s_t100.t010_isMatch( "a" , ".*..a*");


}
