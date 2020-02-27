/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (63.56%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    58.5K
 * Total Submissions: 90.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        v[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            v[i][0] = v[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++)
            v[0][i] = v[0][i - 1] + grid[0][i];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
            }
        }
        return v[m - 1][n - 1];
    }
};
// @lc code=end
