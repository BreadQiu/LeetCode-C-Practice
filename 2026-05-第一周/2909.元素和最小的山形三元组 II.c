/**
*题目：元素和最小的山形三元组 II
*日期：2026.5.4
*/
int minimumSum(int* nums, int numsSize) {
    int*minRight=(int*)malloc(numsSize*sizeof(int));
    int minright=nums[numsSize-1];
    for(int i=numsSize-1;i>=0;i--){
        minright=fmin(minright,nums[i]);
        minRight[i]=minright;
    }
    int ret=INT_MAX;
    int minleft=nums[0];
    for(int i=0;i<numsSize;i++){
        minleft=fmin(minleft,nums[i]);
        if(nums[i]>minleft&&nums[i]>minRight[i]) ret=fmin(ret,minleft+minRight[i]+nums[i]);
    }
    if(ret==INT_MAX) return -1;
    return ret;
}
