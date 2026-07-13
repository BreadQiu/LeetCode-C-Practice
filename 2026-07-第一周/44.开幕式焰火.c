/**
*题目：开幕式焰火
*日期：2026.7.5
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int n;

void dfs(struct TreeNode*root,bool*cnt){
    if(!cnt[root->val]){
        cnt[root->val]=true;
        n++;
    }
    if(root->left!=NULL){
        dfs(root->left,cnt);
    }
    if(root->right!=NULL){
        dfs(root->right,cnt);
    }
}

int numColor(struct TreeNode* root){
    n=0;
    bool cnt[1001]={0};
    if(root!=NULL) dfs(root,cnt);
    return n;
}
