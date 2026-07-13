/**
*题目：数位和相等数对的最大和
*日期：2026.4.23
*/
int maximumSum(int* nums, int numsSize) {
    int cnt[82]={0};
    int i,temp,sum,ret=-1;
    for(i=0;i<numsSize;i++){
        for(sum=0,temp=nums[i];temp>0;temp/=10){
            sum+=temp%10;
        }
        if(cnt[sum]!=0) ret=fmax(ret,nums[i]+cnt[sum]);
        cnt[sum]=fmax(cnt[sum],nums[i]);
    }
    return ret;
}
