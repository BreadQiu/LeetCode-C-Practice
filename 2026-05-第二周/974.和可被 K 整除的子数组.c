/**
*题目：和可被 K 整除的子数组
*日期：2026.5.14
*/
int remaind(int arr,int k){
    if(arr>=0){
        return arr%k;
    }else{
        return (k-(-arr)%k)%k;
    }
}

int subarraysDivByK(int* nums, int numsSize, int k) {
    int*cnt=(int*)calloc(k,sizeof(int));
    cnt[0]=1;
    int sum=0;
    int ret=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        ret+=cnt[remaind(sum,k)];
        cnt[remaind(sum,k)]++;
    }
    return ret;
}
