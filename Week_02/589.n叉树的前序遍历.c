/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// method1：递归解法
#define MAX 10240

void traveTree(int *res, int *retunSize, struct Node *root) {
    if (root == NULL) { return NULL; }
    res[(*retunSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        if (root->children == NULL) { return NULL; }
        traveTree(res, retunSize, root->children[i]);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int *res = (int *)malloc(MAX * sizeof(int));
    *returnSize = 0;
    if (root == NULL) { return NULL; }
    traveTree(res, returnSize, root);
    return res;
}
// @lc code=end

