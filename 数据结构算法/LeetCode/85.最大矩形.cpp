/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (43.33%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 39.2K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        vector<int> v(matrix[0].size(), 0);
        int max_area = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                    v[j] = (matrix[i][j] == '1') ? 1 : 0;
            }
            else
            {
                for (int j = 0; j < matrix[0].size(); j++)
                    v[j] = matrix[i][j] == '1' ? v[j] + 1 : 0;
            }
            max_area = max(max_area, get_max_area(v));
        }
        return max_area;
    }

    int get_max_area(vector<int> &v)
    {
        stack<int> s;
        int max_area = 0;
        for (int i = 0; i < v.size(); i++)
        {
            while (!s.empty() && v[s.top()] >= v[i])
            {
                int tmp = s.top();
                s.pop();
                if (s.empty())
                    max_area = max(v[tmp] * (i - (-1) - 1), max_area);
                else
                    max_area = max(v[tmp] * (i - s.top() - 1), max_area);
            }
            s.push(i);
        }
        while (!s.empty())
        {
            int tmp = s.top();
            s.pop();
            int l = v.size();
            if (s.empty())
                max_area = max(v[tmp] * (l - (-1) - 1), max_area);
            else
                max_area = max(v[tmp] * (l - s.top() - 1), max_area);
        }
        return max_area;
    }
};
// @lc code=end
