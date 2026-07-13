/**
*题目：求根节点到叶节点数字之和
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
 int sum;

 void dfs(struct TreeNode*root,int tmp){
     if(root==NULL){
         return;
     }
     tmp=tmp*10+root->val;
     if(root->left==NULL&&root->right==NULL){
         sum+=tmp;
         return;
     }
     dfs(root->left,tmp);
     dfs(root->right,tmp);
 }

int sumNumbers(struct TreeNode* root) {
    sum=0;
    dfs(root,0);
    return sum;
}
