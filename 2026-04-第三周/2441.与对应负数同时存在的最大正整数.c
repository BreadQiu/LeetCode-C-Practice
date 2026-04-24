/**
*题目：与对应负数同时存在的最大正整数
*日期：2026.4.18
*/
int findMaxK(int* nums, int numsSize) {
    int hash[2002]={0};
    int right,max=-1;
    for(right=0;right<numsSize;right++){
        if(hash[1000-nums[right]]>=1)  max=fmax(max,abs(nums[right]));
        hash[1000+nums[right]]++;
    }
    return max;
}
