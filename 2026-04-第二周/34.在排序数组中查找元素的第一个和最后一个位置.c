/**
*题目：在排序数组中查找元素的第一个和最后一个位置
*日期：2026.4.9
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left,right,now;
    int*ans=(int*)malloc(3*sizeof(int));
    ans[0]=ans[1]=-1;
    returnSize[0]=2;
    if(numsSize==0) return ans;
    for(left=0,right=numsSize-1,now=(left+right)/2;nums[now]!=target;now=(left+right)/2){
        if(nums[now]<target){
            if(now>=right){
                return ans;
            }
            else if(now==right-1){
                now+=(right-now+1)/2;
                left=now;
            }
            else{
                left=now;
                now+=(right-now+1)/2;
            }
        }
        else{
            if(now<=left){
                return ans;
            }
            else if(now==left+1){
                now-=(now-left+1)/2;
                right=now;
            }
            else{
                right=now;
                now-=(now-left+1)/2;
            }
        }
    }
    for(left=right=now;(left>=0&&nums[left]==target)||(right<=numsSize-1&&nums[right]==target);){
        if(left>=0&&nums[left]==target) --left;
        if(right<=numsSize-1&&nums[right]==target) ++right;
    }
    ans[0]=left+1;
    ans[1]=right-1;
    return ans;
}
