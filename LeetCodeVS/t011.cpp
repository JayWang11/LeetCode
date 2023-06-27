#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
/**
 * 11. 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
*/

//class Solution {
//public:
//    // 双指针解法
//    int maxArea(vector<int>& height) {
//        int max = 0;
//        int i = 0 ;
//        int j = height.size() -1 ;
//        while ( i != j){
//            if ( max < min(height[i] , height[j]) * ( j - i)){
//                max = min(height[i] , height[j]) * ( j - i);
//            }
//            if (height[i] < height [j]){
//                 i++;
//            }
//            else
//                j--;
//        }
//        return max;
//    }
//};