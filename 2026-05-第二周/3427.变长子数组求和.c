/**
*题目：变长子数组求和
*日期：2026.5.9
*/
int subarraySum(int* nums, int numsSize) {
    int*s=(int*)malloc((numsSize+1)*sizeof(int));
    s[0]=0;
    for(int i=0;i<numsSize;i++){
        s[i+1]=s[i]+nums[i];
    }
    int ret=0;
    for(int i=0;i<numsSize;i++){
        int start=fmax(0,i-nums[i]);
        ret+=s[i+1]-s[start];
    }
    return ret;
}
