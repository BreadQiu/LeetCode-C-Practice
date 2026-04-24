/**
*题目：长度最小的子数组
*日期：2026.4.17
*/
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left,right,sum=0,min=INT_MAX;
    for(left=right=0;right<numsSize;){
        while(sum<target&&right<numsSize){
            sum+=nums[right];
            right++;
        }
        while(sum>=target){
            min=fmin(min,right-left);
            sum-=nums[left];
            left++;
        }
    }
    if(min==INT_MAX) return 0;
    return min;
}
