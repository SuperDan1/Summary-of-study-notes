/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> t;
            for (int i=0; i<n; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                t.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            v.push_back(t);
        }
        return v;
    }
};
// @lc code=end

