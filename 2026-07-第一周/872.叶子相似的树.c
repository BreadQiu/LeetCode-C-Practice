/**
*题目：叶子相似的树
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

 void function(int*cnt,struct TreeNode*root){
     if(root->left==NULL&root->right==NULL){
         cnt[n++]=root->val;
     }else{
         if(root->left!=NULL){
             function(cnt,root->left);
         }
         if(root->right!=NULL){
             function(cnt,root->right);
         }
     }
 }

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int cnt1[200];
    n=0;
    function(cnt1,root1);
    int cnt1Size=n;
    int cnt2[200];
    n=0;
    function(cnt2,root2);
    int cnt2Size=n;
    if(cnt1Size!=cnt2Size){
        return false;
    }else{
        for(int i=0;i<n;i++){
            if(cnt1[i]!=cnt2[i]){
                return false;
            }
        }
    }
    return true;
}
