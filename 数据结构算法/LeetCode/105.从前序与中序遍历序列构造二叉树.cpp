/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.09%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    42.6K
 * Total Submissions: 66.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0;
        for (; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
                break;
        }
        vector<int> v1 = vector<int>(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> v2 = vector<int>(inorder.begin(), inorder.begin() + i);
        root->left = buildTree(v1, v2);
        v1 = vector<int>(preorder.begin() + i + 1, preorder.end());
        v2 = vector<int>(inorder.begin() + i + 1, inorder.end());
        root->right = buildTree(v1, v2);
        return root;
    }
};
// @lc code=end
