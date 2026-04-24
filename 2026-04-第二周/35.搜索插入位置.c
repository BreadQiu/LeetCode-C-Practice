/**
*题目：搜索插入位置
*日期：2026.4.10
*/
int searchInsert(int* nums, int numsSize, int target) {
    int left,right,now;
    for(left=0,right=numsSize-1;1;){
        now=(left+right)/2;
        if(nums[now]==target) return now;
        else if(nums[now]<target){
            if(now==right) return now+1;
            else if(now==right-1){
                if(target<=nums[right]) return right;
                else return right+1;
            }
            else now+=(right-(left=now)+1)/2;
        }
        else{
            if(now==left) return now;
            else if(now==left+1){
                if(target<=nums[left]) return left;
                else return now;
            }
            else now-=((right=now)-left+1)/2;
        }
    }
}
