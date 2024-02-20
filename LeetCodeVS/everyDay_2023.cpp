#include"everyDay_2023.h"
#include <functional>


int dfs(ListNode*, ListNode* , int);

/*1247. 交换字符使得字符串相同
* 有两个长度相同的字符串 s1 和 s2，且它们其中 只含有 字符 "x" 和 "y"，你需要通过「交换字符」的方式使这两个字符串相同。

每次「交换字符」的时候，你都可以在两个字符串中各选一个字符进行交换。

交换只能发生在两个不同的字符串之间，绝对不能发生在同一个字符串内部。也就是说，我们可以交换 s1[i] 和 s2[j]，但不能交换 s1[i] 和 s1[j]。

最后，请你返回使 s1 和 s2 相同的最小交换次数，如果没有方法能够使得这两个字符串相同，则返回 -1 。

*/
inline int Solution_everyDay::t1247_minimumSwap(string s1, string s2)
{
	vector<int> j = { 0 ,0 };
	// 1. 只有不同项数为偶数时才可以交换为一对相同数组
	// 2. 偶数交换，只需要记录类型 。两种不同的交换类型对应的交换次数不相同 （xx,yy) 1 ， （xy,yx) 2.
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] == 'x') {
				j[0] += 1;
			}
			else j[1] += 1;
		}
	}
	if ((j[0] + j[1]) % 2 != 0) return -1;
	return  j[0]/2+j[1]/2 + max(j[0]%2,0)*2;
}


/*1255. 得分最高的单词集合  !! 难题 ，要看题解，目前没有自己的很好的方法
* 你将会得到一份单词表 words，一个字母表 letters （可能会有重复字母），以及每个字母对应的得分情况表 score。

请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由 letters 里的字母拼写出的 任意 属于 words 单词子集中，分数最高的单词集合的得分。

单词拼写游戏的规则概述如下：

玩家需要用字母表 letters 里的字母来拼写单词表 words 中的单词。
可以只使用字母表 letters 中的部分字母，但是每个字母最多被使用一次。
单词表 words 中每个单词只能计分（使用）一次。
根据字母得分情况表score，字母 'a', 'b', 'c', ... , 'z' 对应的得分分别为 score[0], score[1], ..., score[25]。
本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-score-words-formed-by-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 自定义比较器
//bool cmp(pair<string, int> a, pair<string, int> b) {
//	return a.second < b.second;
//}

int Solution_everyDay::t1224_maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
	// 贪心算法？
		/* 1. 直接遍历，如果该单词全部字符都有，就计算分数并相加 ，删去letters中对应的字母？
		   2. 将所有符合条件的words沿降序排列，贪心算法，取可完成的最高值

		   wooood  woodes wodesss
		   15       13     14
		*/

	typedef pair<int, string> PAIR;
	vector<PAIR> vecWordGrade;
	map< string , int, less<string>> mapWordGrade;  // greater<int> 指定 map沿key值降序排列
	int grade;
	for (string w : words) {
		vector<char> letters_1 = letters;
		grade = 0;
		for (int i = 0; i < w.size() && grade >= 0; i++ ) {
			if (find(letters_1.begin(), letters_1.end(), w[i]) != letters_1.end()) {
				grade += score[w[i] - 'a'];
				letters_1.erase(find(letters_1.begin(), letters_1.end(), w[i]));
			}
			else {
				grade = -1;
			}
		}
		if (grade != -1) { vecWordGrade.push_back(PAIR(grade,w)); }
	}
	grade = 0;
	if (vecWordGrade.empty()) return  grade;
	// 找到分值最大的单词组合，动态规划
	// it
	sort(vecWordGrade.begin(), vecWordGrade.end());
	vector<PAIR>::iterator left = vecWordGrade.begin();
	for (vector<PAIR>::iterator it = vecWordGrade.begin(); it != vecWordGrade.end(); it++) {
		vector<PAIR>::iterator  right = it;
		right++;
		vector<char> letters_1 = letters;
		int grade_tmp = 0;
		// 比较left和right中可以获取的最大grade 与上一组 left和right的中的最大grade，保存最大值并更新 letter
		while (right != vecWordGrade.begin()) {
			right--;
			int i = 0;
			vector<char> letters_1_tmp = letters_1;
			while(find(letters_1.begin(), letters_1.end(), right->second[i]) != letters_1.end()) {
				letters_1.erase(find(letters_1.begin(), letters_1.end(), right->second[i]));
				i++;
			}
			if (i == right->second.size()) grade_tmp += right->first;
			else  letters_1 = letters_1_tmp;

		}
		if (grade < grade_tmp) grade = grade_tmp;
	}
	return grade;
}

int Solution_everyDay::t1224_maxScoreWords_dfs(vector<string>& words, vector<char>& letters, vector<int>& score)
{
	int n = words.size(), res = 0;
	int letter_num[26] = {};
	for (char c :  letters) {
		letter_num[c - 'a']++;
	}
	//lambda表达式!!!
	function<int (vector<string>,int[26], int)> dfs = [=](vector<string> word, int letter[26], int total) ->int {
		// 返回条件 ： 1.到达底部， 2. 超过最大字母数量
		int tmp = 0;  // 该单词的分数
		for (int i = 0; i < words.size(); i++) {
			if (word[i] != "") {
				// 判断是否符合需求
				for (char c : word[i]) {
					if (letter[c - 'a'] != 0) {
						letter[c - 'a']--;
						tmp += score[c - 'a'];
					}
					else
						return 0; // 不符合需求即到底
				}
				word[i] = "";
				return tmp + dfs(word , letter, total);
			}
			else
				continue;
		}
	};
	return dfs(words, letter_num, 0 );

}


/*2363. 合并相似的物品
* 给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。每个数组 items 有以下特质：

items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，weighti 表示第 i 件物品的 重量 。
items 中每件物品的价值都是 唯一的 。
请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， weighti 是所有价值为 valuei 物品的 重量之和 。

注意：ret 应该按价值 升序 排序后返回。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-similar-items
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> Solution_everyDay::t2363_mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2)
{
	// 合并价值相同的物体并计算出总质量
	vector<vector<int>> ret;
	items1.insert(items1.end(), items2.begin(), items2.end());
	int len = items1.size();
	sort(items1.begin(), items1.end());
	vector<vector<int>>::iterator it = items1.begin() + 1;
	while (it != items1.end()) {
		if (it[0][0] == it[-1][0]) {
			it[-1][1] += it[0][1];
			it[0][0] = 1001, it[0][1] = 0;
			len--;
		}
		it++;
	}
	sort(items1.begin(), items1.end());
	return vector<vector<int>>(items1.begin(), items1.begin() + len);
	//return  ret(mapValueWight.begin(), mapValueWight.end());

}
vector<vector<int>> Solution_everyDay::t2363_mergeSimilarItems_Hashmap(vector<vector<int>>& items1, vector<vector<int>>& items2)
{
	// hash map 思维
	map<int, int> mp;
	for (auto& v : items1) {
		mp[v[0]] += v[1];
	}
	for (auto& v : items2) {
		mp[v[0]] += v[1];
	}
	vector<vector<int>> res;
	for (auto& m : mp) { 
		res.push_back({ m.first, m.second  });
	}
	return res;
}


/*面试题 05.02. 二进制数转字符串
* 二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/bianry-number-to-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
string Solution_everyDay::m0502_printBin(double num)
{
	long i = 2;
	string res = "0.";
	//经过提醒，优化一下，在十进制小数位不超过6位时，二进制也最多不超过6位，否则便是无限循环小数。
	// 小小tips： 二进制小数转十进制小数末尾数字必为 5！
	while (i <= pow(2, 6)) {
		cout << i << endl;
		if ((num) /(1.0 / i) == int(num / (1.0 / i))) goto trans;
		else
			i = i << 1;
	}
	return "ERROR";
	trans:
		while (num - int(num) != 0) {
			num *= 2;
			if (num >= 1) {
				res += "1";
				num -= 1;
			}
			else res += "0";
		}
		return res;
}



vector<string> Solution_everyDay::t1487_getFolderNames(vector<string>& names)
{
	//unordered_map 才属于hash表结构，普通map并不是使用的hash表
	unordered_map<string, int > mapNameNew;
	for ( auto &name : names ) {
		if ( !mapNameNew[name]) {
			mapNameNew[name] = 1;
		}
		else {
			int j = mapNameNew[name];
			while (mapNameNew[name+ "(" + to_string(j) + ")"])  j++;
			mapNameNew[name] = j + 1;
			name += "(" + to_string(j) + ")";
			mapNameNew[name] = 1;
		}
	}
	return names;
}

/*982. 按位与为零的三元组
* 给你一个整数数组 nums ，返回其中 按位与三元组 的数目。

按位与三元组 是由下标 (i, j, k) 组成的三元组，并满足下述全部条件：

0 <= i < nums.length
0 <= j < nums.length
0 <= k < nums.length
nums[i] & nums[j] & nums[k] == 0 ，其中 & 表示按位与运算符。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int Solution_everyDay::t0982_countTriplets(vector<int>& nums)
{
	int res = 0;
	unordered_map<int, int> map;
	for (auto i : nums) {
		for (auto j : nums) {
			map[i & j] ++;
		}
	}
	for (auto i : map) {
		for (auto k : nums) {
			if ((i.first & k) == 0)
				res += i.second;
		}
	}
	return res;
}


/*1599. 经营摩天轮的最大利润
* 你正在经营一座摩天轮，该摩天轮共有 4 个座舱 ，每个座舱 最多可以容纳 4 位游客 。你可以 逆时针 轮转座舱，但每次轮转都需要支付一定的运行成本 runningCost 。摩天轮每次轮转都恰好转动 1 / 4 周。

给你一个长度为 n 的数组 customers ， customers[i] 是在第 i 次轮转（下标从 0 开始）之前到达的新游客的数量。这也意味着你必须在新游客到来前轮转 i 次。每位游客在登上离地面最近的座舱前都会支付登舱成本 boardingCost ，一旦该座舱再次抵达地面，他们就会离开座舱结束游玩。

你可以随时停下摩天轮，即便是 在服务所有游客之前 。如果你决定停止运营摩天轮，为了保证所有游客安全着陆，将免费进行所有后续轮转 。注意，如果有超过 4 位游客在等摩天轮，那么只有 4 位游客可以登上摩天轮，其余的需要等待 下一次轮转 。

返回最大化利润所需执行的 最小轮转次数 。 如果不存在利润为正的方案，则返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int Solution_everyDay::t1599_minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
{
	int income = 0;
	int maxIncome = 0;
	//消费者和生产者问题，忙则等待
	//若停止，当前利润位总收入-（转动次数+4）* 开销
	for (int i = 0; i < customers.size();) {
		// 计算收入以及下一回合 (每一次的收入要减去一次转动开销)
		income += max( customers[i], 4) * boardingCost - runningCost;
		i++; 
		customers[i] += max(customers[i - 1] - 4, 0);
		maxIncome = max(maxIncome, income - runningCost * 3);
	
	}
	int pLastNum = customers[customers.size()] -4;

	while (pLastNum > 0) {
		income += min(pLastNum, 4) * boardingCost - runningCost;
		maxIncome = max(maxIncome, income - runningCost * 3);
		pLastNum -= 4;
	}
	return maxIncome;
}

/*1590. 使数组和能被 P 整除 
* 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/make-sum-divisible-by-p
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int Solution_everyDay::t1590_minSubarray(vector<int>& nums, int p)
{
	int res = nums.size(); int sum = 0; int  target = 0; int neet = 0;
	unordered_map<int, int > less;
	less[0] = -1; // 当子串为 0~n ;时
	for (int i = 0; i < nums.size(); i++) { target = (target + nums[i]) % p;  less[target] = i; }
	if (target == 0) return 0;
	for (int i = 0; i < nums.size(); i++) {
		sum = (nums[i] + sum) % p;
		less[sum] = i;
		neet = (sum - target + p) % p;
		if (less.find(neet) != less.end())
			res = min(res, i - less[neet]);
	}

	return res == nums.size() ? -1 : res;
}
/*试题 17.05.  字母与数字
* 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。

示例 1:

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-longest-subarray-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<string> Solution_everyDay::m1705_findLongestSubarray(vector<string>& array)
{
	// 1. 暴力解时间复杂度 O(n^2)  超时 ！
	// 2. hashmap，前缀和
	int sum = 0, left = 0, len = 0;
	unordered_map < int, int >  sums;
	sums[0] = 0;
	for (int i = 0; i < array.size(); i++) {
		if (array[i][0] - 'A' >= 0 && array [i][0] - 'z' <=0 ) sum += 1;
		else sum += -1;
		if (sums.find(sum) != sums.end()) {
			if (i - sums[sum] > len) {
				left = sums[sum];
				len =i - sums[sum] +1 ;
			}
		}
		else sums[sum] = i+1;
	}
	if (len == 0) return {};
	vector<string>  res(array.begin() + max( 0 , left), array.begin() + max(0, left) + len);
	return res ;
}

/*1617. 统计子树中城市之间最大距离
给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，其中 edges[i] = [ui, vi] 表示城市 ui 和 vi 之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。

一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。

对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。

请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。

请注意，两个城市间距离定义为它们之间需要经过的边的数目。

 
*/

vector<int> Solution_everyDay::t1617_countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges)
{
	// 考虑动态规划，记录每个城市之间的链接情况
	return vector<int>();
}

// 失败的写法，没考虑全面
vector<int> Solution_everyDay::t1617_countSubgraphsForEachDiameter_loss(int n, vector<vector<int>>& edges)
{
	// 总共n个城市 ，  2<=n <=15
	unordered_map <int ,vector<int>  >  citys;
	vector<int> res;
	for (auto c : edges) {
		citys[c[0]].push_back(c[1]);
		citys[c[1]].push_back(c[0]);
		res.push_back(0);
	}
	// 排列组合
	function < int(int) > permutation = [](int num) -> int {
		if (num == 1) return 1;
		if (num == 0) return num;
		int res = 1; // C(n,n)
		for (int n = 1; n <= num%2+num/2; n++) {
			int i = 1;
			int s = 1;
			while ( i <= n ) {
				s = s * (num - i + 1) / i;
				i++;
			}
			if (num - n != n) s * 2;
			res += s;
		}
 		return res;
	};
	// 遍历每个可以作为根节点的城市做广度遍历
	function < void(int, int , int) > bfs = [&](int city, int l , int lastCity) -> void {
		if (citys.find(city) != citys.end()) 
		{
			// 这一步需要再考虑下每个子节点能加几个子树 实际上存在着排列组合问题！！！ 
			// 每一个都当作根节点遍历，需要解决重复问题，用一个数组存放
			if (l != 1) res[l - 1] += permutation(citys[city].size()-1);
			else res[l - 1] += citys[city].size();
			for (auto c : citys[city]) {
				if (c == lastCity) continue;
				bfs(c,l  + 1 , city);
			}
		}
	};
	for (auto i : citys)
		bfs(i.first, 1 ,0);
	for (auto &i : res) i= i>0 ? i /= 2:0;
	return res;
}

/*1605. 给定行和列的和求可行矩阵
* 给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。

请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。

请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> Solution_everyDay::t1605_restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
{
	int row_size = rowSum.size();
	int col_size = colSum.size();
	//// 记录行列当前分配情况
	//vector<int> x(row_size,0); // 行
	//vector<int> y(col_size,0); // 列
	vector<vector<int>> res (row_size ,vector<int>(col_size,0)) ; // 参数1： 行 ，参数2 ： 列
	// 只有一行或者一列的情况
	if (row_size == 1) { for (int i = 0; i < col_size; i++) res[0][i] = colSum[i];  return res; }
	if (col_size == 1) { for (int i = 0; i < row_size; i++) res[i][0] = rowSum[i]; return res; }
	// 对角线赋值
	for (int i = 0; i < min(row_size, col_size); i++) { 
		res[i][i] = min(rowSum[i], colSum[i]);
		// 记录分配情况
		rowSum[i] -= res[i][i];
		colSum[i] -= res[i][i];
	}
	for (int i = 0; i < row_size; i++) {  // 按行遍历
		if (rowSum[i]==0) continue;  // 该行已满， 跳过
		for (int j = 0; j < col_size && rowSum[i] != 0; j++) {
			if (colSum[j] == 0) continue; // 该列已满 ，跳过
			res[i][j] = min(rowSum[i], colSum[j]);
			rowSum[i] -= res[i][j];
			colSum[j] -= res[i][j];
		}
	}
	return res;
}


/*1615. 最大网络秩
* n 座城市和一些连接这些城市的道路 roads 共同组成一个基础设施网络。每个 roads[i] = [ai, bi] 都表示在城市 ai 和 bi 之间有一条双向道路。

两座不同城市构成的 城市对 的 网络秩 定义为：与这两座城市 直接 相连的道路总数。如果存在一条道路直接连接这两座城市，则这条道路只计算 一次 。

整个基础设施网络的 最大网络秩 是所有不同城市对中的 最大网络秩 。

给你整数 n 和数组 roads，返回整个基础设施网络的 最大网络秩 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximal-network-rank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。`
*/
int Solution_everyDay::t1615_maximalNetworkRank(int n, vector<vector<int>>& roads)
{
	// 用二维数组记录所有城市的链接道路，排序后找到max 的城市以及max-1的城市 ，确定最大值
		// 用二维数组记录所有城市的链接道路，排序后找到max 的城市以及max-1的城市 ，确定最大值
	if (!roads.size()) return 0;
	unordered_map < int, vector<int> > map_c;
	unordered_map < int, vector<int> > map_r;
	vector<vector<bool>> connect(n, vector<bool>(n, false));
	for (auto r : roads) {
		connect[r[0]][r[1]] = true;
		connect[r[1]][r[0]] = true;
		map_c[r[0]].push_back(r[1]);
		map_c[r[1]].push_back(r[0]);
	}
	int res = 0;
	int m = 0, sec = 0;
	for (auto c : map_c) {
		int l = c.second.size();
		if (l > m) sec = m;
		else if (m > l) sec = max(sec, l);
		m = max(m, l);
		map_r[l].push_back(c.first);
	}
	if (map_r[m].size() > 1)
		for (int i = 0; i < map_r[m].size() - 1; i++) {
			for (int j = i + 1; j < map_r[m].size(); j++) {
				res = 2 * m - (connect[map_r[m][i]][map_r[m][j]] ? 1 : 0);
				if (res == (2 * m)) return res;
			}
		}
	else
		for (int i = 0; i < map_r[sec].size(); i++) { res = m + sec - (connect[map_r[m][0]][map_r[sec][i]] ? 1 : 0); if (res == m + sec) return res; }
	return res;
}

/*2488. 统计中位数为 K 的子数组
* 给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。

统计并返回 nums 中的 中位数 等于 k 的非空子数组的数目。

注意：

数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
子数组是数组中的一个连续部分。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-subarrays-with-median-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* */

int Solution_everyDay::t2488_countSubarrays(vector<int>& nums, int k)
{
	 //1. 判断k是否再nums中存在
	 //2. 沿k中心延申
	 //3. 记录前缀和，排序后用双指标遍历把时间复杂度从O(n^2) 降到 O(n)
	 //4. ！！！重要思想 ，不需要从中心开始延申记录，从左向右遍历，只需要找到差值为 0 or 1 的位置即可 ！！！
	int res = 0, sum = 0, prev0 = 0, prev1 = 0;
	unordered_map <int, int > sums;
	sums[0] = 1;
	function <int(int)> sign = [](int num) -> int{
		if (num == 0) {
			return 0;
		}
		return num > 0 ? 1 : -1;
	};
	int ki = find(nums.begin(), nums.end(), k) - nums.begin();
	for (int i = 0; i < nums.size(); i++) {
		sum += sign(nums[i] - k);
		if (i < ki) {
			sums[sum] ++;
		}
		else {
			prev0 =  sums.find( sum) != sums.end() ?  sums[sum] :0 ;
			prev1 = sums.find( sum -1) != sums.end() ? sums[sum -1] : 0;
			res += prev0 + prev1;
		}
	}
	return res;
}

//1054. 距离相等的条形码
vector<int> Solution_everyDay::t1054_rearrangeBarcodes(vector<int>& barcodes)
{
	// 贪心算法，正反两遍遍历
	vector < pair <int, int > > n;
	int num[10001] = { 0 };
	for (auto i : barcodes) {
		num[i] += 1;
	}
	for (int i = 0; i < 10001; i++) {
		if (num[i])
			n.push_back({i,num[i]});
	}
	sort(n.begin(), n.end(), []( auto i , auto j ) -> bool {
		return i.second > j.second ? true : false;
		});
	int i = 0;
	for (auto it : n) {
		for (int j = 0; j < it.second; j++) {
			barcodes[i] = it.first;
			i += 2;
			if (i >= barcodes.size())
				i = 1;
		}
	}
	int t = 0;
	for (int i1 = 0; i1 < barcodes.size(); i1++) {
		if (t == barcodes[i1]) {
			cout << t;
			break;
		}
		t = barcodes[i1];
	}
	return barcodes;
}

/**1335. 工作计划的最低难度
你需要制定一份 d 天的工作计划表。工作之间存在依赖，要想执行第 i 项工作，你必须完成全部 j 项工作（ 0 <= j < i）。

	你每天 至少 需要完成一项任务。工作计划的总难度是这 d 天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。

	给你一个整数数组 jobDifficulty 和一个整数 d，分别代表工作难度和需要计划的天数。第 i 项工作的难度是 jobDifficulty[i]。

	返回整个工作计划的 最小难度 。如果无法制定工作计划，则返回 - 1 。
**/
int Solution_everyDay::t1335_minDifficulty(vector<int>& jobDifficulty, int d)
{
	if (jobDifficulty.size() < d) return -1;
	else if (jobDifficulty.size() == d || d == 1) {
		return accumulate(jobDifficulty.begin(), jobDifficulty.end(),0);
	}
	return 0;
}



int Solution_everyDay::LCP_41_flipChess(vector<string>& chessboard)
{

	// bfs 深度遍历每个可能的黑棋位置会导致的变化量
	int x_len;
	int y_len;
	int reson = 0;
	vector < pair<int, int >>  q; 
	x_len = chessboard.size();
	y_len = chessboard[0].size();
	auto BFS = [&](vector<string> cb, int x, int y) {
		int score = 0;
		vector <pair < int, int > > q2 = { { x,y } };
		vector <pair < int, int > > temp;
		cb[x][y] = 'X';
		while (!q2.empty()) {
			//遍历八个方向
			for (int a = -1; a <= 1; a++) {
				for (int b = -1; b <= 1; b++) {
					int x1 = q2.front().first;
					int y1 = q2.front().second;
					if (a == 0 && b == 0) continue;
					x1 += a; y1 += b;
					if (x1 < 0 || y1 < 0 || x1 >= x_len || y1 >= y_len)
						continue;
					while (cb[x1][y1] == 'O') {
						temp.push_back({ x1, y1 });
						x1 += a, y1 += b;
						if (x1 < 0 || y1 < 0 || x1 >= x_len || y1 >= y_len)
							break;
					}
					if (x1 >= 0 && y1 >= 0 && x1 < x_len && y1 < y_len) {
						if (cb[x1][y1] == 'X' && !temp.empty()) {
							score += temp.size();
							q2.insert(q2.end(), temp.begin(), temp.end());
							for (auto t : temp) {
								cb[t.first][t.second] = 'X';
							}
						}
					}
					temp.clear();

				}
			}
			q2.erase(q2.begin());
		}
		return score;
	};

	// 提前找出可能的黑子位置
	for (int i = 0; i < x_len; i++) {
		for (int j = 0; j < y_len; j++) {
			if (chessboard[i][j] == 'O') {
				for (int a = -1; a <= 1; a++) {
					for (int b = -1; b <= 1; b++) {
						int i1 = i;
						int j1 = j;
						i1 += a;
						j1 += b;
						if (i1 >= 0 && j1 >= 0 && i1 < x_len && j1  < y_len && chessboard[i1 ][j1 ] == '.')
						{
							pair<int, int > t = { i1 , j1 };
							if (find(q.begin(), q.end(),t) == q.end())
								q.push_back(t);
						}
					}
				}
			}
		}
	}
	for (auto t : q) {
		int r = BFS(chessboard, t.first, t.second);
		reson =  reson > r  ? reson : r;
	}


	// 直接遍历所有空位
	
	//for (int x = 0; x < x_len; x++) {
	//	for (int y = 0; y < y_len; y++) {
	//		int r = BFS(chessboard, x, y);
	//		reson = reson > r ? reson : r;
	//	}
	//}
	return 	reson;
}

/*1186. 删除一次得到子数组最大和
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。
换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

 
*/
int Solution_everyDay::t1186_maximumSum(vector<int>& arr)
{	
	// 动态规划 + kadane算法， 简直离谱
	// kadane算法： 求子序列最大和，Kadane算法扫描一次整个数列的所有数值，在每一个扫描点计算以该点数值为结束点的子数列的最大和（ 正数和 ）。
	//该子数列由两部分组成：以前一个位置为结束点的最大子数列、该位置的数值。因为该算法用到了“最佳子结构”（以每个位置为终点的最大子数列都是基于其前一位置的最大子数列计算得出）
	int dp0 = arr[0], dp1 = 0, res = 0;
	for (int i = 1; i < arr.size(); i++) {
		dp1 = max(dp0, dp1 + arr[i]);
		dp0 = max(dp0, 0) + arr[i];
		res = max(res, max(dp1, dp0));
	}
	return res;
}


/*1681. 最小不兼容性
给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性 是该子集里面最大值和最小值的差。

请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 - 1 。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。
*/
int Solution_everyDay::t1681_minimumIncompatibility(vector<int>& nums, int k)
{
	// 先 判断下能否划分为k个大小相同的子集？即相同数字是否大于k？
	// 排序后用贪心算法？ 
	vector <int> nums_s(nums.size()+1, 0);
	vector < vector<int> > nums_son(k);
	int s = 0 , res= 0 , m = nums.size()/k;
	sort(nums.begin(), nums.end());
	for (auto a : nums) {
		// 数量+1
		nums_s[a]++;

		// 子序列已满
		if (nums_son[s].size() == m) {
			while (nums_son[s].size() == m) {
				s++;
			}
			nums_son[s].push_back(a);
		}
		else {
			if (nums_s[a] > m)
				return -1;
			else if (nums_s[a] + s <= k)
				nums_son[s - 1 + nums_s[a]].push_back(a);
			else
				nums_son[k - nums_s[a]].push_back(a);
		}
	}
	
	for (auto a : nums_son) {
		res += *(a.end() - 1) - *(a.begin());
	}

	return res;
}


	
ListNode* Solution_everyDay::t0445_addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int sz1 = 0, sz2 = 0 , dis = 0;
	auto h1 = l1;
	auto h2 = l2;
	while (l1 || l2) {
		if (l1) sz1++;
		if (l2) sz2++;
		l1->next;
		l2->next;
	}
	auto l = sz1 > sz2 ? h1 : h2;
	auto s = sz1 < sz2 ? h1 : h2;
	dis = abs(sz1 - sz2);
	// 递归调用 
	if (dfs(l, s, dis)) {
		ListNode* prep = new ListNode(1, l);
		l = prep;
	}
	return l;
}


/*2178. 拆分成最多数目的正偶数之和
给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的正偶数之和，且拆分出来的正偶数数目 最多 。
比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。
它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。
*/
vector<long long> Solution_everyDay::t2178_maximumEvenSplit(long long finalSum)
{
	if (finalSum % 2 == 1) return {};
	vector<long long > res;
	for (long i = 2; i * 2 < finalSum; i += 2) {
		res.push_back(i);
		finalSum -= i;
	}
	res.push_back(finalSum);
	return res;
}


/*648. 单词替换
在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
你需要输出替换之后的句子。
*/
string Solution_everyDay::t0648_replaceWords(vector<string>& dictionary, string sentence)
{
	map<int, int, greater<int>> stock_t_p;
	stock_t_p.begin()->second;
	Trie* trie = new Trie();
	// 构建字典树 
	for (auto& d : dictionary) {
		Trie* cur = trie;
		for (auto& c : d) {
			if (!cur->children.count(c))
				cur->children[c] = new Trie();
			cur = cur->children[c];
		}
		cur->children['#'] = new Trie();
	}
	vector<string> sp = split(sentence, ' ');
	string ret;
	for (auto w : sp) {
		if (!ret.empty()) ret += ' ';
		ret += findRoot(w, trie);
	}
	return ret;
}

int Solution_everyDay::t0931_minFallingPathSum(vector<vector<int>>& matrix)
{
	//动态规划
	int m=0;
	for (int i = 1; i < matrix.size(); i++) {
		int j = 0;
		matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
		for (j = 1; j < matrix.size() - 1; j++) {
			matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
		}
		matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
	}
	m = matrix[matrix.size()-1][0];
	for (auto& p : matrix[matrix.size() - 1])
		m = min(m, p);
	return m;
}

/*979. 在二叉树中分配硬币
给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。

在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。

返回使每个结点上只有一枚硬币所需的移动次数。
*/
int Solution_everyDay::t0979_distributeCoins(TreeNode* root)
{
	//  深度遍历 
	int res = t0979_dfs(root, 0);
	return res;
}

/*834. 树中距离之和
给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。

给定整数 n 和数组 edges ， edges[i] = [ai, bi]表示树中的节点 ai 和 bi 之间有一条边。

返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i 个节点与所有其他节点之间的距离之和。
*/
vector<int> Solution_everyDay::t0834_sumOfDistancesInTree(int n, vector<vector<int>>& edges)

{
	// 换根dfs
	if (n == 1 && edges.size() == 1) return{ 1 };
	if (n == 1 && edges.size() == 0) return { 0 };
	vector<vector<int>> dist(n);
	vector<int> res(n,0);
	vector<int> sonSum (n,1);
	for (auto e : edges) {
		dist[e[0]].push_back(e[1]);
		dist[e[1]].push_back(e[0]);

	}
	function <void(int, int, int)> dfs = [&](int root, int father, int dep) {
		res[0] += dep;
		for (auto son : dist[root]) {
			if (son != father) {
				dfs(son, root, dep + 1);
				sonSum[root]+= sonSum[son];
				res[root] += res[son];
			}
		}
	};
	dfs(0, 0, 0);

	function<void(int, int)> reRoot = [&](int root, int father) {
		if (father != -1)
			res[root] += res[father] + n - 2*sonSum[root];
		for (auto& son : dist[root]) {
			if (son != father) {
				reRoot(son, root);
			}
		}
	};
	reRoot(0, -1);
	return res;
}

/*1851. 包含每个查询的最小区间
给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。
再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度 。如果不存在这样的区间，那么答案是 -1 。
以数组形式返回对应查询的所有答案。
*/
vector<int> Solution_everyDay::t1851_minInterval(vector<vector<int>>& intervals, vector<int>& queries)
{
	// 记录 各组
	map < int, vector<int>> in_len;
	// pair : 1: 有边界， 2：长度
	set<pair<int, int>> point;
	vector<int> res( queries.size(),-1);
	int j = 0;
	for (auto& i : intervals) {
		in_len[i[1] - i[0] + 1].push_back(j);
		j++;
	}
	j = 0;
	for (auto& p : queries) {
		point.emplace(p, j);
		j++;
	}
	for (auto& len : in_len) {
		for (auto& i : len.second) {
			//lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。
			auto it = point.lower_bound({ intervals[i][0] , -1 });
			while (it->first < intervals[i][1])
				res[it->second] = len.first;
		}
	}
	return res;
}


/*874. 模拟行走机器人
机器人在一个无限大小的 XY 网格平面上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 commands ：
	-2 ：向左转 90 度
	-1 ：向右转 90 度
	1 <= x <= 9 ：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物 obstacles 。第 i 个障碍物位于网格点  obstacles[i] = (xi, yi) 。
机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续尝试进行该路线的其余部分。
返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。（即，如果距离为 5 ，则返回 25 ）
注意：
北表示 +Y 方向。
东表示 +X 方向。
南表示 -Y 方向。
西表示 -X 方向。
*/
int Solution_everyDay::t0874_robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
{
	// 记录最远位置 （可否省略？)
	// 记录当前位置
	// 障碍物碰撞检测
	int Max = 0, d = 0;
	vector<int > pos = { 0 , 0 };
	set<int> obs;
	// 用加密 把二维坐标转换成 一维数组， 再配合set 大幅优化 速度和空间！！！
	for (auto& o : obstacles) {
		obs.insert(o[0] * 6001 + o[1]);
	}
	// row[x]{y} cow[y]{x}
	vector<pair<int, int>> dict = { {0,1} ,{ 1,0} , { 0, -1} ,{-1,0} };
	for (auto& c : commands) {
		if (c < 0) {
			d = (d + 4 + (c == -1 ? 1 : -1)) % 4;
		}
		else {
			// 碰撞检测 
			for (int i = 1; i <= c; i++) {
				pos = { pos[0] + dict[d].first , pos[1] + dict[d].second };
				if (obs.find(pos[0]*6001+ pos[1]) != obs.end()) {
					pos = { pos[0] - dict[d].first  , pos[1] - dict[d].second };
					i = c;
				}

			}
			Max = max(Max, pos[0] * pos[0] + pos[1] * pos[1]);
		}
	}
	//Max = max(Max, pos.first * pos.first + pos.second * pos.second);
	return Max;
}


/*918. 环形子数组的最大和
给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。
子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
*/
int Solution_everyDay::t0918_maxSubarraySumCircular(vector<int>& nums)
{
	// 动态规划 
	int len = nums.size();
	if (len == 1) return nums[0];
	int dp = 0, dp1 = 0, Max = nums[0], sum = 0, Min = -nums[0];
	for (auto& n : nums) {
		sum += n;
		dp = max(n, dp + n);
		dp1 = max(-n, dp1 + (-n));
		Max = max(Max, dp);
		Min = max(Min, dp1);

	}
	// 如果第一次循环发现整个数列相加为正 ， 找到最大的子串
	return Max > 0 ? max(Max , sum+Min): Max ;
}

/*1499. 满足不等式的最大值
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。
也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。
请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
*/
int Solution_everyDay::t1499_findMaxValueOfEquation(vector<vector<int>>& points, int k)
{
	/// <summary>
	///  其实可以用 队列 ，set来进行优化
	/// </summary>
	/// <param name="points"></param>
	/// <param name="k"></param>
	/// <returns></returns>
	int res = INT_MIN, Max = 0, x = 0, i = 1;
	while (i < points.size()) {
		cout << " x  :" << points[x][0] << "_" << points[x][1] << endl;
		cout << " Max  :" << points[Max][0] << "_" << points[Max][1] << endl;
		cout << " i  :" << points[i][0] << "_" << points[i][1] << endl;

		if (points[x][1] - points[Max][1] >= points[x][0] - points[Max][0])
			Max = x;
		if (points[i][0] - points[Max][0] <= k) {
			res = max(res, points[i][1] + points[Max][1] + points[i][0] - points[Max][0]);
			i++;
			x++;
		}
		else {
			if (points[i][0] - points[x][0] > k) {
				x++;
				i++;
				Max = x;
				continue;
			}
			while (points[i][0] - points[Max][0] > k && Max <= x) {
				Max++;
			}
			for (int x1 = Max; x1 <= x; x1++) {
				if (points[x1][1] - points[Max][1] > points[x1][0] - points[Max][0])
					Max = x1;
			}
		}
		cout << " res :" << res << endl;

	}

	return res;
}

/*
*/
int Solution_everyDay::t2208_halveArray(vector<int>& nums)
{ 
	priority_queue < double > t1 ( nums.begin() , nums.end());
	double sum = accumulate( nums.begin() , nums.end(), 0), del = 0;;

	int i = 0;
	while (del < sum / 2) {
		double t = t1.top();
		t /= 2;
		del += t;
		i++;
		t1.pop();
		t1.push(t);
	}
	return i;
}


/*2569. 更新数组后处理求和查询
提示
困难
36
相关企业
给你两个下标从 0 开始的数组 nums1 和 nums2 ，和一个二维数组 queries 表示一些操作。总共有 3 种类型的操作：
操作类型 1 为 queries[i] = [1, l, r] 。你需要将 nums1 从下标 l 到下标 r 的所有 0 反转成 1 或将 1 反转成 0 。l 和 r 下标都从 0 开始。
操作类型 2 为 queries[i] = [2, p, 0] 。对于 0 <= i < n 中的所有下标，令 nums2[i] = nums2[i] + nums1[i] * p 。
操作类型 3 为 queries[i] = [3, 0, 0] 。求 nums2 中所有元素的和。
请你返回一个数组，包含所有第三种操作类型的答案。
*/
vector<long long> Solution_everyDay::t2569_handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries)
{
	long long sum = 0; 
	int j = 0 , len = nums1.size();
	vector<long long> res;
	SegMentTree<int> st (nums1);
	for (auto& n : nums2) sum += n;
	for (auto& q : queries) {
		switch (q[0])
		{
		case  1:
			st.change(1, q[1]+1, q[2]+1);
			break;
		case 2:
			sum +=  q[1] * st.find( 1, 1 , len  );
			break;
		case 3:
			res.push_back(sum);
		}
		j++;
	}
	return res;
}

/*2050. 并行课程 III
提示
困难
60
相关企业
给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n 。同时给你一个二维整数数组 relations ，其中 relations[j] = [prevCoursej, nextCoursej] ，表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）。
同时给你一个下标从 0 开始的整数数组 time ，其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。
请你根据以下规则算出完成所有课程所需要的 最少 月份数：
如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
你可以 同时 上 任意门课程 。 
请你返回完成所有课程所需要的 最少 月份数。

注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。
*/
int Solution_everyDay::t2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
{
	// 动态规划， 找到每个学科学习需要的最小月份事件
	vector<priority_queue<int>> Cour(n);
	vector<int> dp(n,0);
	int res = 0;
	for (auto& r : relations) {
		Cour[r[1]-1].push(r[0]);
	}
	function  <int(int)> dfs = [&](int c) -> int {
		if (Cour[c-1].empty()) {
			dp[c - 1] = time[c - 1];
			return time[c - 1];
		}
		else {
			int cur = 0;
			while(!Cour[c - 1].empty()){
				int t = Cour[c - 1].top();
				if (!dp[t-1])
					dp[t-1] = dfs(t);
				cur = max(cur, time[c - 1] + dp[t - 1]);
				Cour[c - 1].pop();
			}
			return cur;
		}
	};
	for (int i = 1; i <= n; i++) {
		if (!dp[i - 1])
			dp[i - 1] = dfs(i);
	}
	for (auto &d : dp) {
		res = max(d, res);
	}
	return res;
}
/*142. 环形链表 II
中等

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。
*/
ListNode* Solution_everyDay::t0142_detectCycle(ListNode* head)
{
	// 快慢表， 双指针
	ListNode* l = head;
	ListNode* h = head;
	while (h->next) {
		h = h->next;
		h = h-> next;
		if (h == nullptr) return nullptr;
		l = l->next;
		if (l == h) break;
	}
	while (l != head) {
		l = l -> next;
		head = head->next;
	}
	return head;
}



void Solution_everyDay::t0143_reorderList(ListNode* head)
{
	ListNode* h = head;
	stack<ListNode*> list;
	while (h) {
		list.push(h);
		h = h->next;
	}
	h = head;
	ListNode* t = list.top();
	while (true) {

		if (h != head) t->next = head;
		if (t == head || list.top() == head) { list.top()->next = nullptr; break;};
		list.top()->next = head->next;
		head->next = list.top();
		head = list.top()->next;
		t = list.top();
		list.pop();
	}
}


/*2681. 英雄的力量
提示
困难
25
相关企业
给你一个下标从 0 开始的整数数组 nums ，它表示英雄的能力值。如果我们选出一部分英雄，这组英雄的 力量 定义为：
i0 ，i1 ，... ik 表示这组英雄在数组中的下标。那么这组英雄的力量为 max(nums[i0],nums[i1] ... nums[ik])2 * min(nums[i0],nums[i1] ... nums[ik]) 。
请你返回所有可能的 非空 英雄组的 力量 之和。由于答案可能非常大，请你将结果对 109 + 7 取余。
*/
int Solution_everyDay::t2681_sumOfPower(vector<int>& nums)
{
	// 本质是最大值平方*最小值之和的问题
	sort(nums.begin(), nums.end());

	int len = nums.size();
	int res = 0, mod = 1e9 + 7;
	long long dp = 0, sum = 0;
	for (auto & n : nums) {
		dp = (sum +n) % mod;
		sum = (sum + dp) % mod;
		res = (int)((res + n *  dp  %mod * n) % mod);
	}
	return res;
}


/*822. 翻转卡片游戏
中等
28
相关企业
在桌子上有 N 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。
我们可以先翻转任意张卡片，然后选择其中一张卡片。
如果选中的那张卡片背面的数字 X 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。
哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0。
其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。
如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
*/
int Solution_everyDay::t0822_flipgame(vector<int>& fronts, vector<int>& backs)
{
	set <int> q1;
	set <int> q2;
	int res = 0;
	for (int i = 0; i < fronts.size(); i++) {
		if (fronts[i] == backs[i])
			q2.insert(fronts[i]);
		else {
			q1.insert(fronts[i]);
			q1.insert(backs[i]);
		}

	}
	while (!q1.empty() && !q2.empty() && *q2.begin()<= *q1.begin()) {
		if (*q2.begin() == *q1.begin()) {
			q1.erase(q1.begin());
			q2.erase(q2.begin());
		}
		else
			q2.erase(q2.begin());
	}
	if (q1.empty()) return 0;
	return *q1.begin();
}

/*722. 删除注释
提示
中等
115
相关企业
给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第 i 行源码。 这表示每行源码由 '\n' 分隔。

在 C++ 中有两种注释风格，行内注释和块注释。

字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。
字符串/* 表示一个块注释，它表示直到下一个（非重叠）出现的 "/*"之间的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串/* /并没有结束块注释，因为注释的结尾与开头相重叠。
第一个有效注释优先于其他注释。

如果字符串//出现在块注释中会被忽略。
同样，如果字符串/*出现在行或块注释中也会被忽略。
如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。
样例中没有控制字符，单引号或双引号字符。
比如，source = "string s = "/* Not a comment. * / 不会出现在测试样例里。
此外，没有其他内容（如定义或宏）会干扰注释。
我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的 /*总是开始新的注释。
最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。

从源代码中删除注释后，需要以相同的格式返回源代码。
*/
vector<string> Solution_everyDay::t0722_removeComments(vector<string>& source)
{
	string s1 = "//", s2 = "/*", s3 = "*/";
	int flag = 0;
	string tl = "";
	for (int s = 0; s < source.size(); s++) {
		// 已有注释， 只有 /* 这一种情况
		string t = "";
		for (int i = 0; i < source[s].size(); i++) {
			if ( !flag){
				if (source[s][i] == '/' && i + 1 < source[s].size()) {
					if (source[s][i + 1] == '/') {
						i = source[s].size();
						continue;
					}
					else if (source[s][i + 1] == '*') {
						flag = 1;
						i++;
						continue;
					}
				}

					t += source[s][i];
			}
			else{
				if (source[s][i] == '*' && i + 1 < source[s].size()) {
					if (source[s][i + 1] == '/') {
						flag = 0;
						i++;
					}
				}
			}
		}

		if (t== "") {
			if ( !flag ) {
				tl = "";
			}
			source.erase(source.begin() + s);
			s--;
		}
		else if (tl != ""&& !flag) {
			source[s - 1] = tl + t;
			tl = "";
			source.erase(source.begin() + s);
			s--;
		}
		else if(flag){
			tl = t;
			source[s] = t;
		}
		else
			source[s] = t;
	}
	return source;
}

/*980. 不同路径 III
困难
272
相关企业
在二维网格 grid 上，有 4 种类型的方格：

1 表示起始方格。且只有一个起始方格。
2 表示结束方格，且只有一个结束方格。
0 表示我们可以走过的空方格。
-1 表示我们无法跨越的障碍。
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
1 <= grid.length * grid[0].length <= 20*/
int Solution_everyDay::t0980_uniquePathsIII(vector<vector<int>>& grid)
{
	/*回溯法*/

	/*int x_l = grid.size(), y_l = grid[0].size();
	int res = 0, d = 0, x_s = 0, y_s = 0;
	function  <void(int, int, int)> dfs = [&](int x, int y, int dist) -> void {
		if (grid[x][y] == 2)
			res += dist == d ? 1 : 0;
		else if (grid[x][y] >= 0) {
			dist += 1;
			grid[x][y] = -1;
			if (x > 0)
				dfs(x - 1, y, dist);
			if (x < x_l - 1)
				dfs(x + 1, y, dist);
			if (y > 0)
				dfs(x, y - 1, dist);
			if (y < y_l - 1)
				dfs(x, y + 1, dist);
			grid[x][y] = 0;
		}
	};
	for (int i = 0; i < x_l; i++) {
		for (int j = 0; j < y_l; j++) {
			if (grid[i][j] == 1) {
				x_s = i, y_s = j;
			}
			else if (grid[i][j] == 0)
				d++;
		}
	}
	dfs(x_s, y_s, -1);
	return res;*/

	/* 状态压缩 + 记忆化搜索*/
	int m = grid.size(), n = grid[0].size(), vis = 0, sx, sy;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] < 0) vis |= 1 << (i * n + j); // 把障碍方格算上
			else if (grid[i][j] == 1) sx = i, sy = j; // 起点
		}
	}

	int all = (1 << m * n) - 1;  // 全集（所有格子的坐标集合）
	unordered_map<int, int> memo;
	function<int(int, int, int)> dfs = [&](int x, int y, int vis) -> int {
		int p = x * n + y;
		if (x < 0 || x >= m || y < 0 || y >= n || vis >> p & 1)
			return 0; // 不合法
		vis |= 1 << p; // 标记访问过 (x,y)，因为题目要求「不能重复通过同一个方格」
		if (grid[x][y] == 2) // 到达终点
			return vis == all; // 必须访问所有的无障碍方格
		int key = (p << m * n) | vis; // 把参数压缩成一个整数（左移 m*n 是因为 vis 至多有 m*n 个比特）
		if (memo.count(key)) return memo[key]; // 之前算过
		return memo[key] = dfs(x - 1, y, vis) + dfs(x, y - 1, vis) +
			dfs(x + 1, y, vis) + dfs(x, y + 1, vis);
	};
	return dfs(sx, sy, vis);


}

/*1289. 下降路径最小和 II
提示
困难
159
相关企业
给你一个 n x n 整数矩阵 grid ，请你返回 非零偏移下降路径 数字和的最小值。

非零偏移下降路径 定义为：从 grid 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。
*/
int Solution_everyDay::t1289_minFallingPathSum(vector<vector<int>>& grid)
{
	return 0;
}

//深度遍历
int dfs (ListNode* l, ListNode* s, int dis) {
	int sum;
	if (!(l->next || s->next)) {
		sum = l->val + s->val;
		l->val = sum % 10;
		return sum / 10;
	}
	else
	{
		if (dis) {
			sum = l->val + dfs(l->next, s, dis--);
		}
		else {
			sum = l->val + s->val + dfs(l->next, s->next, 0);
		}

		l->val = sum % 10;
		return sum / 10;
	}
}


// 自动向map里面添加数据，如果存在就累加，不存在就直接加
void  mapAdd(map<int, int>& map, vector<int> nums) {
	if (map.find(nums[0]) != map.end()) {
		map[nums[0]] += nums[1];
	}
	else map[nums[0]] = nums[1];
}




