/**
*题目：二叉树的后序遍历
*日期：2026.7.4
*/
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
  int n;

 void function(struct TreeNode*root,int*ret){
     if(root->left!=NULL){
         function(root->left,ret);
     }
     if(root->right!=NULL){
         function(root->right,ret);
     }
     ret[n++]=root->val;
 }

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    n=0;
    int*ret=(int*)malloc(sizeof(int)*100);
    if(root!=NULL) function(root,ret);
    *returnSize=n;
    return ret;
}
