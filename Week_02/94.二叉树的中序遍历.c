/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 500

void travelTree(struct TreeNode* root, int *pRet, int *nodeNum) {
    if (root == NULL) { return; } 
    travelTree(root->left, pRet, nodeNum);
    if (*nodeNum >= MAX) { return; }
    pRet[(*nodeNum)++] = root->val;
    travelTree(root->right, pRet, nodeNum);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int nodeNum = 0;
    int *pRet = (int *)malloc(MAX * sizeof(int));
    travelTree(root, pRet, &nodeNum);
    *returnSize = nodeNum;
    return pRet;
}
// @lc code=end

