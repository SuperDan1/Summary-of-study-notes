/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (71.10%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 21.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<int> v;
    vector<int> postorder(Node *root)
    {
        if (!root)
            return v;
        func(root);
        return v;
    }
    void func(Node *root)
    {
        if (!root)
            return;
        for (int i = 0; i < root->children.size(); i++)
            func(root->children[i]);
        v.push_back(root->val);
    }
};
// @lc code=end
