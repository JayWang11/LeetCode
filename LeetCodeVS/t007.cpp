#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
/**
 * 7. ������ת
����һ�� 32 λ���з������� x �����ؽ� x �е����ֲ��ַ�ת��Ľ����

�����ת���������� 32 λ���з��������ķ�Χ??[??231,?? 231???? 1] ���ͷ��� 0��

���軷��������洢 64 λ�������з��Ż��޷��ţ���
??

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/reverse-integer
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//class Solution {
//public:
//    int reverse(int x) {
//        long  new_x = 0;
//        // long limit = pow(2,31);
//        while ( x != 0){
//            new_x = new_x*10 + x%10;
//            x = x/10 ;
//        }
//        if ( new_x > pow(2,31)-1 || new_x < -pow(2,31)  )
//            return 0;
//        return  (int)new_x;
//    }
//};