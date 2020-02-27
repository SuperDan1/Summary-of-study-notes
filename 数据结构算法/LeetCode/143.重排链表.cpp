/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (53.62%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 29.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode *node)
    {
        if (!node)
            return;
        ListNode *head = new ListNode(0);
        head->next = node;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        ListNode *l1 = head->next;
        ListNode *l2 = pre;
        while (l1 && l2)
        {
            l1->next = l2;
            l2->next = l1->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        node = head->next;
        return;
    }
};
// @lc code=end
