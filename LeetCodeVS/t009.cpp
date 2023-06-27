#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

/**
 * 9. 回文数
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
 
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