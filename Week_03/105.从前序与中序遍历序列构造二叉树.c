/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd) {
        return NULL;
    }
    
    // 获取根节点的值
    int rootVal = preorder[preStart];
    // 从中序遍历中查找根节点的索引
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (rootVal == inorder[i]) {
            inIndex = i;
        }
    }
    // 从中序遍历中，根据根节点左右的数据个数，计算前序遍历中的左右字树的数据索引，方便递归填写索引值
    int preLeftSize = inIndex - inStart;

    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    node->left = build(preorder, preStart + 1, preStart + preLeftSize,
                       inorder, inStart, inIndex - 1);
    node->right = build(preorder, preStart + preLeftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd);
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorder == NULL || inorder == NULL) {
        return NULL;
    }
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}


// @lc code=end

