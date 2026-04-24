/**
*题目：K 和数对的最大数目
*日期：2026.4.21
*/
int maxOperations(int* nums, int numsSize, int k) {
    int*cnt=(int*)calloc((k+1),sizeof(int));
    //memset(cnt,0,(k+1)*sizeof(cnt));
    //int cnt[10000000001]={0};
    int i,ret=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]<k){
            if(cnt[k-nums[i]]>0){
                cnt[k-nums[i]]--;
                ret++;
            }
            else{
                cnt[nums[i]]++;
            }
        }
    }
    free(cnt);
    return ret;
}
