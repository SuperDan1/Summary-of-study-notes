/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.23%)
 * Likes:    1379
 * Dislikes: 0
 * Total Accepted:    201.3K
 * Total Submissions: 493.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> stack1;
        map<char, char> m;
        m['}'] = '{';
        m[')'] = '(';
        m[']'] = '[';
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                stack1.push(c);
            else
            {
                if (stack1.empty())
                    return false;
                else if (stack1.top() == m[c])
                    stack1.pop();
                else
                    return false;
            }
        }
        if (!stack1.empty())
            return false;
        return true;
    }
};
// @lc code=end
