/**
*题目：最大连续1的个数 III
*日期：2026.4.17
*/
int longestOnes(int* nums, int numsSize, int k) {
    int left,right,sum0=0,max=0;
    for(left=right=0;right<numsSize;right++){
        sum0+=nums[right]==0?1:0;
        max=fmax(max,right-left);
        while(sum0>k){
            sum0-=nums[left]==0?1:0;
            left++;
        }
    }
    return fmax(max,right-left);
}
