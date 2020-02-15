/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    61.1K
 * Total Submissions: 108.3K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        stack<TreeNode *> s1, s2;
        s1.push(p);
        s2.push(q);
        while (!s1.empty() || !s2.empty())
        {
            TreeNode *tmp1 = s1.top();
            TreeNode *tmp2 = s2.top();
            s1.pop();
            s2.pop();
            if (tmp1 != tmp2)
                return false;
            if (tmp1->right) s1.push(tmp1->right);
            if (tmp1->left) s1.push(tmp1->left);
            if (tmp2->right) s2.push(tmp2->right);
            if (tmp2->left) s2.push(tmp2->left);
        }
        return true;
    }
};
// @lc code=end
