/**
*题目：乘积小于 K 的子数组
*日期：2026.4.17
*/
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if(k==0) return 0;
    int left,right;
    long long plus=1,sum=0;
    for(left=right=0;right<numsSize;right++){
        plus*=nums[right];
        while(left<right&&plus>=k){
            plus/=nums[left];
            left++;
        }
        if(nums[right]<k){
            sum+=right-left+1;
        }
    }
    return sum;
}
