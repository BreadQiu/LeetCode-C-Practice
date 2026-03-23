/**
*题目：删除并获得点数
*日期：2026.3.20
*/
int nums1Size;

void BubbleSort(int* nums,int numsSize)//泡沫排序
{
    int i,j,temp;
    for(i=0;i<numsSize-1;i++)
    for(j=0;j<numsSize-i-1;j++)
    if(nums[j]<nums[j+1])
    {
        temp=nums[j];
        nums[j]=nums[j+1];
        nums[j+1]=temp;
    }
}

int pointtemp(int* nums,int* pointall)
{
    int i,j,temp,point;
    for(i=0,j=0,temp=nums[i]+1,point=0;i<nums1Size;point=0)
    {
        if(temp!=nums[i]+1)
        {
            if(j>1) pointall[j-1]=fmax(pointall[j-2],pointall[j-1]);
            pointall[j++]=0;
        }
        for(temp=nums[i];i<nums1Size&&temp==nums[i];i++) point+=temp;
        if(j<2) pointall[j++]=point;
        else if(j==2) pointall[j++]=point+pointall[0];
        else pointall[j++]=fmax(pointall[j-3],pointall[j-2])+point;
    }
    if(j==1) return pointall[j-1];
    return fmax(pointall[j-1],pointall[j-2]);
}

int deleteAndEarn(int* nums, int numsSize) {
    int pointall[10000];
    nums1Size=numsSize;
    BubbleSort(nums,numsSize);
    return pointtemp(nums,pointall);
}
