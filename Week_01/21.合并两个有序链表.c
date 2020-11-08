/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// method1：迭代
// 时间复杂度：O(m+n)
// 空间复杂度：O(1)
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->val = -1;
    res->next = NULL;
    struct ListNode* prev = res;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    if (l1 != NULL) {
        prev->next = l1;
    } else {
        prev->next = l2;
    }
    return res->next;
}


// method2：递归
// 时间复杂度：O(m+n)
// 空间复杂度：O(m+n)
// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//     if (l1 == NULL) {
//         return l2;
//     } else if (l2 == NULL) {
//         return l1;
//     } else if (l1->val < l2->val) {
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     } else {
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//     }
// }
// @lc code=end

