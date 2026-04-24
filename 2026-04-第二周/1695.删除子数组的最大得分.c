/**
*题目：删除子数组的最大得分
*日期：2026.4.8
*/
int maximumUniqueSubarray(int* nums, int numsSize) {
    int i,left,right,hash[10001]={0},sum=0,max=0;
    //memset(hash,0,sizeof(hash));
    for(left=0,right=0;right<numsSize;++right){
        ++hash[nums[right]];
        sum+=nums[right];
        if(hash[nums[right]]>1){
            max=fmax(sum-nums[right],max);
            for(;nums[left]!=nums[right];++left){
                --hash[nums[left]];
                sum-=nums[left];
            }
            --hash[nums[left]];
            sum-=nums[left];
            ++left;
        }
    }
    return fmax(sum,max);
}
