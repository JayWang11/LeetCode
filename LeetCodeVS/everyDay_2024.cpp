#include "everyDay_2024.h"

TreeNode* test(vector<int>& pro, vector<int>& ino , int l_p, int r_p , int l_i , int r_i) {
	
	if (r_p < l_p)return nullptr;
	TreeNode* n = new TreeNode(pro[l_p]);
	if (r_p == l_p) return n;
	int mid = pro[l_p], mid_idx = find(ino.begin(), ino.end(), mid) - ino.begin();
	// �Ȳ����
	if (mid_idx > l_i) {
		n->left = test(pro, ino ,l_p+1,l_p+mid_idx , l_i ,  mid_idx-1 );
	}
	// �ٲ��ұ�
	if (mid_idx < r_i) {

		
	}n->right = test(pro, ino ,r_p - r_i+ mid_idx+1 , r_p , mid_idx+1, r_i );
	return n;
}
/*105. ��ǰ��������������й��������
�е�
���������������� preorder �� inorder ������ preorder �Ƕ���������������� 
inorder ��ͬһ����������������빹�����������������ڵ㡣 
*/
TreeNode* everyDay_2024::t0105_buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.size() == 0) return nullptr;
	int s = preorder.size()-1;
	return test(preorder , inorder,0 , s, 0 ,s );
}

