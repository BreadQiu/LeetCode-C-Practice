/**
*题目：增量元素之间的最大差值
*日期：2026.4.20
*/
int maximumDifference(int* nums, int numsSize) {
    int ret=-1,minPrice=INT_MAX,right;
    for(right=0;right<numsSize;right++){
        if(minPrice<nums[right]) ret=fmax(ret,nums[right]-minPrice);
        minPrice=fmin(minPrice,nums[right]);
    }
    return ret;
}
