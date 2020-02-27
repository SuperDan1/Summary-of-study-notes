/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.74%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 59.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> v;
        if (!root)
            return v;
        deque<TreeNode *> dq;
        dq.push_front(root);
        int flag = 1;
        while (!dq.empty())
        {
            vector<int> res;
            int n = dq.size();
            if (flag)
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *tmp = dq.front();
                    dq.pop_front();
                    res.push_back(tmp->val);
                    if (tmp->left)
                        dq.push_back(tmp->left);
                    if (tmp->right)
                        dq.push_back(tmp->right);
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *tmp = dq.back();
                    dq.pop_back();
                    res.push_back(tmp->val);
                    if (tmp->right)
                        dq.push_front(tmp->right);
                    if (tmp->left)
                        dq.push_front(tmp->left);
                }
            }
            v.push_back(res);
            flag = !flag;
        }
        return v;
    }
};
// @lc code=end
