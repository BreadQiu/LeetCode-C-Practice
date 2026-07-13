/**
*题目：二叉树的前序遍历
*日期：2026.5.20
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
int function(struct TreeNode*root,int* ret,int retSize){
     ret[retSize++]=root->val;
     if(root->left!=NULL) retSize=function(root->left,ret,retSize);
     if(root->right!=NULL) retSize=function(root->right,ret,retSize);
     return retSize;
 }

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    int*ret=(int*)malloc(100*sizeof(int));
    *returnSize=function(root,ret,0);
    return ret;
}
