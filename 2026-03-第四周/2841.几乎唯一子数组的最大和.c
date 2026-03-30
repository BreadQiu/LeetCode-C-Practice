/**
*题目：几乎唯一子数组的最大和
*日期：2026.3.26
*/
long long maxSum(int* nums, int numsSize, int m, int k) {
    int diff=0,tempin,tempout,i,j;
    long long max=0,sum=0;
    for(i=0;i<k;++i){
        sum+=nums[i];
        for(tempin=0,j=fmax(0,i-k+1);j<i;++j)
        {
            if(nums[i]==nums[j])
            {
                tempin=1;
                break;
            }
        }
        if(tempin==0) ++diff;
    }
    if(diff>=m) max=fmax(sum,max);
    for(;i<numsSize;++i){
        sum+=nums[i];
        sum-=nums[i-k];
        for(tempin=0,tempout=0,j=fmax(0,i-k+1);j<i;++j)
        {
            if(tempin==0&&nums[i]==nums[j]) tempin=1;
            if(tempout==0&&nums[i-k]==nums[j]) tempout=1;
            if(tempin==1&&tempout==1) break;
        }
        if(tempin==0) ++diff;
        if(tempout==0) --diff;
        if(diff>=m) max=fmax(sum,max);
    }
    return max;
}
