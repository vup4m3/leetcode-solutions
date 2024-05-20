#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* cur1 = 0;
    struct ListNode* cur2 = 0;
    struct ListNode* result_head = 0;
    struct ListNode* result_tail = 0;
    struct ListNode* new_node = 0;

    int num = 0, carry = 0, val1 = 0, val2 = 0;
    cur1 = l1;
    cur2 = l2;
    do {
        if (cur1) {
            val1 = cur1->val;
            cur1 = cur1->next;
        }

        if (cur2) {
            val2 = cur2->val;
            cur2 = cur2->next;
        }

        num = val1 + val2 + carry;
        if (num >= 10) {
            carry = 1;
            num %= 10;
        } else {
            carry = 0;
        }
        new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = num;
        new_node->next = 0;

        if (!result_head) {
            result_head= new_node;
            result_tail = result_head;
        } else {
            result_tail->next = new_node;
            result_tail = result_tail->next;
        }

        val1 = 0;
        val2 = 0;
    } while (cur1 || cur2 || carry);

    return result_head;
}
