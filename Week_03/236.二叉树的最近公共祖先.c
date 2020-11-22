/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
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
// 成立条件：
/*
1. 左子树包含 && 右子树包含
2. 当前节点即为最近祖先 && （左子树包含 || 右子树包含）
*/
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return left;
    } else {
        return right;
    }
}

// @lc code=end

