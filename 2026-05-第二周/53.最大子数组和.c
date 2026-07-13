/**
*题目：最大子数组和
*日期：2026.5.10
*/
int maxSubArray(int* nums, int numsSize) {
    int ret=nums[0],max=nums[0];
    for(int i=1;i<numsSize;i++){
        max=fmax(max,0)+nums[i];
        ret=fmax(ret,max);
    }
    return ret;
}
