/**
*题目：二分查找
*日期：2026.4.11
*/
int search(int* nums, int numsSize, int target) {
    int left,right,now;
    for(left=0,right=numsSize-1;1;){
        now=(left+right)/2;
        if(nums[now]==target) return now;
        else if(nums[now]<target){
            if(now==right) return -1;
            else if(now==right-1){
                if(target==nums[right]) return right;
                else return -1;
            }
            else now+=(right-(left=now)+1)/2;
        }
        else{
            if(now==left) return -1;
            else if(now==left+1){
                if(target==nums[left]) return left;
                else return -1;
            }
            else now-=((right=now)-left+1)/2;
        }
    }
}
