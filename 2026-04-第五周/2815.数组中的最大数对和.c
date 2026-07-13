/**
*题目：数组中的最大数对和
*日期：2026.4.30
*/
int maxSum(int* nums, int numsSize) {
    int cnt[10]={0};
    int right;
    int ret=-1;
    for(right=0;right<numsSize;right++){
        int tmp=nums[right];
        int max=0;
        while(tmp>0){
            max=fmax(max,tmp%10);
            tmp/=10;
        }
        if(cnt[max]>0){
            ret=fmax(ret,cnt[max]+nums[right]);
        }
        cnt[max]=fmax(cnt[max],nums[right]);
    }
    return ret;
}
