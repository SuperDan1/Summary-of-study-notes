/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {

//     }
// };

class Solution
{
    vector<int> v;

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            v.push_back(tmp->val);
            if (tmp->right) s.push(tmp->right);
            if (tmp->left) s.push(tmp->left);

        }
        return v;
    }
};
// @lc code=end
