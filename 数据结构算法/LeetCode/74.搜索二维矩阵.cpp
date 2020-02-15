/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] < target)
                i++;
            else if (matrix[i][j] > target)
                j--;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end

