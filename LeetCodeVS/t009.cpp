#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

/**
 * 9. ������
����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

���磬121 �ǻ��ģ��� 123 ���ǡ�
 
*/
//class Solution {
//public:
//    bool isPalindrome(int x) {
//        long newNum = 0;
//        int x_1 = x;
//        if ( x < 0)
//            return false;
//        while ( x ){
//            newNum = newNum*10 + x%10;
//            x /= 10;
//        }
//        if ( x_1 == newNum)
//            return true;
//        else
//            return false;
//    }
//};