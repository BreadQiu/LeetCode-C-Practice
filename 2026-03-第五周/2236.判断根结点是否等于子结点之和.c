/**
*题目：判断根结点是否等于子结点之和
*日期：2026.3.30
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkTree(struct TreeNode* root) {
    if(root->val==root->left->val+root->right->val) return true;
    return false;
}
