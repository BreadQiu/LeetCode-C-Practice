/**
*题目：打家劫舍
*日期：2026.3.13
*/
int bill1;
void elsebill(int* nums, int numsSize, int i, int bill){
    int j;
    for(j=i;j<=numsSize-4;j+=2)
    {
        if(nums[j]+nums[j+2]<nums[j+1]+nums[j+3]&&nums[j]<nums[j+1])
        elsebill(nums,numsSize,j+3,bill+nums[j+1]);
        bill+=nums[j];
    }
    if(j==numsSize-1) bill+=nums[j];
    else if(j==numsSize-2) bill+=(nums[j]>nums[j+1]?nums[j]:nums[j+1]);
    else bill+=(nums[j]+nums[j+2]>nums[j+1]?nums[j]+nums[j+2]:nums[j+1]);
    if(bill>bill1) bill1=bill;
}
int rob(int* nums, int numsSize) {
    bill1=0;
    elsebill(nums,numsSize,0,0);
    return bill1;
}
