/**
*题目：路径总和
*日期：2026.7.13
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool found;
 int target;

 void dfs(struct TreeNode*root,int sum){
     if(root==NULL||found){
         return;
     }
     sum+=root->val;
     if(root->left==NULL&&root->right==NULL){
         if(sum==target){
             found=true;
         }
         return;
     }
     dfs(root->left,sum);
     dfs(root->right,sum);

 }

bool hasPathSum(struct TreeNode* root, int targetSum) {
    found=false;
    if(root!=NULL){
        target=targetSum;
        dfs(root,0);
    }
    return found;
}
