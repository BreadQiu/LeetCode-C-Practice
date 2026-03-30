/**
*题目：子数组最大平均数 I
*日期：2026.3.24
*/
double findMaxAverage(int* nums, int numsSize, int k) {
    int i,tp=0;
    long double sum=0;
    for(i=0;i<k;i++) sum=tp+=nums[i];
    for(;i<numsSize;i++)
    {
        tp=tp-nums[i-k]+nums[i];
        sum=fmax(tp,sum);
    }
    return sum/k;
}
