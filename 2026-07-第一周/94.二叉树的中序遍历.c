/**
*题目：二叉树的中序遍历
*日期：2026.7.1
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
     ret[n++]=root->val;
     if(root->right!=NULL){
         function(root->right,ret);
     }
 }

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    n=0;
    int*ret=(int*)malloc(sizeof(int)*100);
    if(root!=NULL) function(root,ret);
    *returnSize=n;
    return ret;
}
