#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
/**
 * 11. ʢ���ˮ������
����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��

�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

�����������Դ�������ˮ����

˵�����㲻����б������
*/

//class Solution {
//public:
//    // ˫ָ��ⷨ
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