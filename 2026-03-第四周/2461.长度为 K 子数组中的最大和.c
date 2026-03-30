/**
*题目：长度为 K 子数组中的最大和
*日期：2026.3.28
*/
long long maximumSubarraySum(int* nums, int numsSize, int k) {
    int i,same=0,hash[100000];
    long long sum=0,maxSum=0;
    memset(hash,0,sizeof(hash));
    for(i=0;i<numsSize;++i){
        sum+=nums[i];
        ++hash[nums[i]-1];
        if(hash[nums[i]-1]>1) ++same;
        if(i==k-1&&same==0) maxSum=fmax(sum,maxSum);
        if(i<k) continue;
        sum-=nums[i-k];
        --hash[nums[i-k]-1];
        if(hash[nums[i-k]-1]>0) --same;
        if(same==0) maxSum=fmax(sum,maxSum);
    }
    return maxSum;
}
