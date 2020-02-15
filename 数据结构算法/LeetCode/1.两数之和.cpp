/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

// 模板
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//     }
// };
// 解法一
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n = nums.size();
        for (int i=0; i<n-1; i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (nums[i] == target-nums[j])
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};
// @lc code=end

