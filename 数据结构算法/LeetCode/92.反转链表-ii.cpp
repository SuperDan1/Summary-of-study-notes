/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (48.24%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 68.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *node, int m, int n)
    {
        if (!node || m >= n || n < 0)
            return node;
        ListNode *head = new ListNode(0);
        head->next = node;
        ListNode *end1 = NULL;
        ListNode *end2 = NULL;
        ListNode *begin2 = NULL;
        ListNode *begin3 = NULL;
        ListNode *cur = head;
         n = n - m+1;
        while (--m && cur)
            cur = cur->next;
        if (m)
            return NULL;
        end1 = cur;
        end2 = cur->next;
        cur = cur->next;
        ListNode *pre = NULL;
       

        while (n-- && cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
     
        begin2 = pre;
        begin3 = cur;
        end1->next = begin2;
        end2->next = begin3;
        return head->next;
    }
};
// @lc code=end
