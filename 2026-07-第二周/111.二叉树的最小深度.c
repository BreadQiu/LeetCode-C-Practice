/**
*题目：二叉树的最小深度
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
     if(root->left==NULL&&root->right==NULL){
         depth=fmin(depth,tmp);
     }else{
         if(root->left!=NULL){
             dfs(root->left,tmp+1);
         }
         if(root->right!=NULL){
             dfs(root->right,tmp+1);
         }
     }
 }

int minDepth(struct TreeNode* root) {
    depth=INT_MAX;
    if(root!=NULL){
        dfs(root,1);
    }
    return depth==INT_MAX?0:depth;
}
