/**
*题目：有序三元组中的最大值 II
*日期：2026.5.5
*/
long long maximumTripletValue(int* nums, int numsSize) {
    int*maxRight=(int*)malloc(numsSize*sizeof(int));
    int maxright=nums[numsSize-1];
    for(int i=numsSize-1;i>=0;i--){
        maxRight[i]=maxright;
        maxright=fmax(maxright,nums[i]);
    }
    int maxleft=nums[0];
    long long ret=-1LL;
    for(int i=1;i<numsSize-1;i++){
        ret=fmax(ret,1LL*(maxleft-nums[i])*maxRight[i]);
        maxleft=fmax(maxleft,nums[i]);
    }
    if(ret<0) return 0;
    return ret;
}
