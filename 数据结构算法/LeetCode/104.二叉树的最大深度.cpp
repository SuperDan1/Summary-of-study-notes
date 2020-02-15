/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (71.50%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    122.7K
 * Total Submissions: 170.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int max_depth = 0;
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, 1));
        while (!s.empty())
        {
            pair<TreeNode *, int> p = s.top();
            s.pop();
            max_depth = max(max_depth, p.second);
            if (p.first->right)
                s.push(make_pair(p.first->right, p.second + 1));
            if (p.first->left)
                s.push(make_pair(p.first->left, p.second + 1));
        }
        return max_depth;
    }
};
// @lc code=end
