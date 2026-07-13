/**
*题目：二叉树中第二小的节点
*日期：2026.7.8
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int min;
 int minup;

 void dfs(struct TreeNode*root){
     if(root->left!=NULL){
         if(root->left->val==min){
             dfs(root->left);
         }else{
             minup=minup==-1?root->left->val:fmin(minup,root->left->val);
         }
         if(root->right->val==min){
             dfs(root->right);
         }else{
             minup=minup==-1?root->right->val:fmin(minup,root->right->val);
         }
     }
 }

int findSecondMinimumValue(struct TreeNode* root) {
    min=root->val;
    minup=-1;
    dfs(root);
    return minup;
}
