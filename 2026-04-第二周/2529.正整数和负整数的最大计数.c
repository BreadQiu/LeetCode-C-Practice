/**
*题目：正整数和负整数的最大计数
*日期：2026.4.13
*/
int maximumCount(int* nums, int numsSize) {
    int left,right,now;
    if(numsSize==1) return nums[0]==0?0:1;
    for(left=0,right=numsSize-1;1;){
        now=(left+right)/2;
        if(nums[now]>0){
            if(now==left) return fmax(now,numsSize-now);
            else right=now;
        }
        else if(nums[now]<0){
            if(now==right-1){
                if(nums[right]>0) return fmax(right,numsSize-right);
                else if(nums[right]<0) return fmax(now+2,numsSize-now-2);
                else{
                    ++now;
                    break;
                }
            }
            else left=now;
        }
        else break;
    }

    left=right=now;
    while(left>=0&&nums[left]==0) --left;
    ++left;
    while(right<=numsSize-1&&nums[right]==0) ++right;
    --right;
    return fmax(left,numsSize-right-1);
}
