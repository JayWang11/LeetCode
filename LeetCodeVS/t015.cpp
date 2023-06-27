
#include "leetCodeT100.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 3)
            if ((nums[0] + nums[1] + nums[2]) == 0) return ans;
            else return {};
        return {};
    }
};