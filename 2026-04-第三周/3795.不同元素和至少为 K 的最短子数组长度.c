/**
*题目：不同元素和至少为 K 的最短子数组长度
*日期：2026.4.17
*/
int minLength(int* nums, int numsSize, int k) {
    int left,right,sum=0,min=INT_MAX,hash[100001]={0};
    for(left=right=0;right<numsSize;){
        while(sum<k&&right<numsSize){
            hash[nums[right]]++;
            if(hash[nums[right]]==1) sum+=nums[right];
            right++;
        }
        while(sum>=k){
            min=fmin(min,right-left);
            hash[nums[left]]--;
            if(hash[nums[left]]==0) sum-=nums[left];
            left++;
        }
    }
    if(min==INT_MAX) return -1;
    return min;
}
