/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
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

// 基本思路：如果左节点不为空，则把该左节点加入父节点的右节点前

void flatten(struct TreeNode* root){ 
    if (root == NULL) {
        return;
    }
    flatten(root->left);
    flatten(root->right);
    
    // 后续遍历
    struct TreeNode* tmpRight = NULL;
    tmpRight = root->right;
    root->right = root->left;
    root->left = NULL;  // 这里一定不能忘记左赋值为空

    struct TreeNode* p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    p->right = tmpRight;

    return;
}
// @lc code=end

