/**
*题目：两个值之间的最小绝对差值
*日期：2026.3.28
*/
int minAbsoluteDifference(int* nums, int numsSize) {
    int i,j,min=100,mintemp=100;
    for(i=0;i<numsSize;++i){
        if(nums[i]==1){
            for(j=fmax(0,i-min+1);j<fmin(numsSize,i+min);++j){
                if(nums[j]==2) mintemp=fmin(abs(i-j),mintemp);
            }
        min=mintemp;
        }
    }
    if(min==100) return -1;
    return min;
}
