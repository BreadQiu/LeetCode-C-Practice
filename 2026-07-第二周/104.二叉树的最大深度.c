/**
*题目：二叉树的最大深度
*日期：2026.7.12
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int depth;

 void dfs(struct TreeNode*root,int tmp){
     if(root==NULL){
         return;
     }
     depth=fmax(depth,tmp+1);
     dfs(root->left,tmp+1);
     dfs(root->right,tmp+1);
 }

int maxDepth(struct TreeNode* root) {
    depth=0;
    dfs(root,0);
    return depth;
}
