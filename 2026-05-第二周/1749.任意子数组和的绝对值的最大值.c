/**
*题目：任意子数组和的绝对值的最大值
*日期：2026.5.10
*/
int maxAbsoluteSum(int* nums, int numsSize) {
    int ret=0;
    for(int min=0,max=0,s=0,i=1;i<=numsSize;i++){
        min=fmin(min,s);
        max=fmax(max,s);
        s+=nums[i-1];
        ret=fmax(ret,fmax(abs(s-min),abs(s-max)));
    }
    return ret;
}
