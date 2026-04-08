/**
*题目：山脉数组的峰顶索引
*日期：2026.4.1
*/
int peakIndexInMountainArray(int* arr, int arrSize) {
    int i,j,tp;
    for(i=0,j=arrSize-1,tp=(arrSize+1)/2-1;1;)
    {
        if(arr[tp-1]<arr[tp]&&arr[tp]>arr[tp+1]) return tp;
        else if (arr[tp-1]>arr[tp]) tp-=((j=tp)-i+1)/2;
        else if (arr[tp-1]<arr[tp]) tp+=(j-(i=tp)+1)/2;
    }
}
