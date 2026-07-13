/**
*题目：比较双调部分的和
*日期：2026.4.25
*/
int compareBitonicSums(int* nums, int numsSize) {
    long long sum=0;
    int i;
    for(i=0;nums[i]<=nums[i+1];i++){
        sum+=nums[i];
    }
    i++;
    for(;i<numsSize;i++){
        sum-=nums[i];
    }
    if(sum>0) return 0;
    if(sum<0) return 1;
    return -1;
}
