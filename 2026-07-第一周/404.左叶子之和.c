/**
*题目：左叶子之和
*日期：2026.7.7
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ret;

void dfs(struct TreeNode* root){
    if(root->left!=NULL){
        if(root->left->left==NULL&&root->left->right==NULL){
            ret+=root->left->val;
        }else{
            dfs(root->left);
        }
    }
    if(root->right!=NULL){
        dfs(root->right);
    }
}

int sumOfLeftLeaves(struct TreeNode* root) {
    ret=0;
    dfs(root);
    return ret;
}
