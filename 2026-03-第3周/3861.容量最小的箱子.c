/**
*题目：容量最小的箱子
*日期：2026.3.22
*/
int minimumIndex(int* capacity, int capacitySize, int itemSize) {
    int size,i,temp=1;
    for(size=itemSize;temp==1;size++)
    {
        temp=0;
        for(i=0;i<capacitySize;i++)
        {
            if(size==capacity[i]) return i;
            if(temp==0&&size<capacity[i]) temp=1;
        }
    }
    return -1;
}
