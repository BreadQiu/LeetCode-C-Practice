/**
*题目：连续数组
*日期：2026.6.12
*/
int findMaxLength(int* nums, int numsSize) {
    int cnt[200001]={0};
    int ret=0;
    for(int tmp=0,i=0;i<numsSize;i++){
        tmp+=nums[i]?1:-1;
        if(!tmp){
            ret=i+1;
        }else if(!cnt[tmp+100000]){
            cnt[tmp+100000]=i+1;
        }else{
            ret=fmax(ret,i+1-cnt[tmp+100000]);
        }
    }
    return ret;
}
